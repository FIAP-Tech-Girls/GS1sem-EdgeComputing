#include <LiquidCrystal.h>
// Definindo LCD
LiquidCrystal lcd(12, 11, 10, 9, 6, 5, 3);

// Variável de armazenamento da temperatura
float temperatura;

// Onde está conectado o sensor de temperatura
int sensorTempPin = A0;
int sensorUmidPin = A1;

// Definindo os leds
int ledVerde = 7;
int ledVermelho = 8;

// Definindo buzzer
int buzzer = 4;

void setup()
{
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  lcd.begin(16,2); 
}

void loop()
{
  	// Lê o valor analogo da temperatura
    int leitorTemperatura = analogRead(sensorTempPin);
  	
  	/* Converte a temperatura recebida em Celcius */
    temperatura = (leitorTemperatura * (5000 / 1024) - 500) / 10;
  
  	// Lendo o valor anaalógico agora do potenciometro como umidade
  	int leitorUmidade = analogRead(sensorUmidPin);
  	
  	// Essa parte lê e mapeia um valor de umidade
    int umidade = map(leitorUmidade, 0, 1023, 0, 100);
  
   // Condição se estiver tudo ok!
   if((temperatura >= 0 && temperatura <= 10) 
      && (umidade >=85 && umidade<=95))
   {
    	digitalWrite(ledVerde, HIGH);
     	digitalWrite(ledVermelho, LOW);
     	noTone(buzzer);
   }
  
  //Condição caso algum deles não esteja adequado
  if((temperatura < 0 || temperatura > 10)
     || (umidade < 85 || umidade > 95))
  {
    	digitalWrite(ledVerde, LOW);
    	digitalWrite(ledVermelho, HIGH);
    	tone(buzzer,1000);
  }
  
  // Mostrando temperatura e umidade no LCD
  lcd.setCursor(0,0);
  lcd.print("Temperatura");
  lcd.setCursor(0,1);
  lcd.print(temperatura);
  lcd.print("C");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Umidade");
  lcd.setCursor(0,1);
  lcd.print(umidade);
  lcd.print("%");
  delay(2000);
}
