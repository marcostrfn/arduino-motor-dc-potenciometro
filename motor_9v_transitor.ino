
#include <TM1637Display.h>


#define CLK 5 // Pin CLK
#define DIO 6 // Pin DIO

TM1637Display display(CLK, DIO);



//Variable donde almacenaremos el valor del potenciometro
long valorPotenciometro;

int MOTOR = 3;
int valor;

void setup() {
  // put your setup code here, to run once:

  display.setBrightness(7);
  pinMode(MOTOR, OUTPUT);
  Serial.begin(9600);

  Serial.println("Inicio de sketch - motor y potenciometro");

  analogWrite(MOTOR, 0);

  

}

void loop() {


  // leemos del pin A0 valor
  valorPotenciometro = analogRead(A0);
  valor = map(valorPotenciometro, 0, 1024, 0, 255);

  Serial.print("Potenciometro ");
  Serial.print(valorPotenciometro);
  Serial.print(" - ");
  Serial.println(valor);

  display.showNumberDec(valor);

  analogWrite(MOTOR, valor);

}
