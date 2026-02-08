#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

const int piezoPin = 13;
char outputChar = '\0';
int sensorReading = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bleKeyboard.begin();

  Serial.println("Bluetooth ready to pair");

}

void loop() {
  sensorReading = analogRead(piezoPin);
  Serial.println(sensorReading);

  if (bleKeyboard.isConnected()) {

    if (sensorReading >=1000) {
      
      Serial.println("Knock!");
      outputChar = '\n';
      bleKeyboard.print(outputChar);
      
      bleKeyboard.releaseAll();
      //delay(1000);
      sensorReading = 0;
      //Keyboard.press(KEY_LEFT_CTRL);
      //Keyboard.press('n');

      //delay(100);
      //Keyboard.releaseAll();
  
  }

  }
  
  // put your main code here, to run repeatedly:

}
