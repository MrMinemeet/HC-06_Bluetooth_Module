#include <SoftwareSerial.h>

// Zweite serielle Schnittstelle 1x PC(Pin 0&1) 1xBluetooth Modul(Pin 2&3)
SoftwareSerial serialbluetooth(2, 3);


void setup() {
  serialbluetooth.begin(9600);
  Serial.begin(9600);

}

void loop() {
  if(serialbluetooth.available() > 0)
  {
    String text = serialbluetooth.readString();
    //Serial.println((String)text);

    Serial.println(text);

    if(text.substring(0) == "ein\r\n")
      digitalWrite(LED_BUILTIN, HIGH);

    if(text.substring(0) == "aus\r\n")
      digitalWrite(LED_BUILTIN, LOW);
  }

}
