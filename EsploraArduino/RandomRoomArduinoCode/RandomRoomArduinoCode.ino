#include <Esplora.h>

void setup() {
  Serial.begin(9600);
  Esplora.writeRGB(0,0,1);
}

void loop() {
  int accelerometerX = Esplora.readAccelerometer(X_AXIS);
  int accelerometerY = Esplora.readAccelerometer(Y_AXIS);
  int switchButtonUp = Esplora.readButton(SWITCH_UP);
  int switchButtonDown = Esplora.readButton(SWITCH_DOWN);

  

  // TRATAMENTO DA MENSAGEM RECEBIDA DA GODOT 3.5
  int byteMessage = Serial.read();
  if (Serial.available() > 0){ // Verifica se há dados sendo envidados ao Serial
    if (byteMessage == 49){ // Código envidado pela Godot ao passar de fase
      Esplora.writeRGB(0,100,0);
      Esplora.tone(1319, 100);
      delay(100);
      Esplora.tone(1568, 100);
      delay(100);
      Esplora.tone(1760, 100);
      delay(100);
      Esplora.tone(1976, 100);
      delay(100);
      Esplora.writeRGB(1,1,1);
      Esplora.tone(2093, 100);
      delay(100);
      Esplora.tone(2349, 100);
      delay(100);
      Esplora.tone(1319, 100);
      delay(100);
      Esplora.tone(2349, 100);
      Esplora.writeRGB(1,100,1);
      delay(100);
    }
    if (byteMessage == 50) {
    Esplora.writeRGB(100, 0, 0);
    Esplora.tone(400, 200);
    delay(250);
    Esplora.tone(300, 200);
    delay(250);
    Esplora.writeRGB(200, 0, 0);
    Esplora.tone(250, 300);
    delay(350);
    Esplora.tone(200, 200);
    delay(250);
    Esplora.writeRGB(255, 0, 0);
    Esplora.tone(150, 300);
    delay(350);
    Esplora.tone(100, 400);
    delay(500);
     }

    Esplora.writeRGB(1,1,1);
    Esplora.noTone();
  }
  

  // ENVIO DA MENSAGEM PARA A GODOT 3.5
  Serial.print("tx"); // Etiqueta do valor do acelerômetro X
  Serial.print(":"); // Divisor de entre etiqueta e valor
  Serial.print(accelerometerX); // Valor do acelerômetro
  
  Serial.print("#"); // Divisor das etiquetas

  Serial.print("ty");
  Serial.print(":");
  Serial.print(accelerometerY);

  Serial.print("#");

  Serial.print("bu");
  Serial.print(":");
  Serial.print(switchButtonUp);

  Serial.print("#");

  Serial.print("bd");
  Serial.print(":");
  Serial.print(switchButtonDown);
  
  Serial.print("]"); // Marcador de fim de String

  
  delay(10);
}
