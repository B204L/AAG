int led = 14;

void setup() {

Serial.begin(19200);

pinMode(led, OUTPUT);

}
String inData = "";

void loop() {

while (Serial.available() > 0) {
  char received = Serial.read();
  inData.concat(received);

    if (received == '\n') {
    }
}
if (inData == "led\n") {
  digitalWrite(led, HIGH);
  inData == "";    
  }
if (inData == "ledoff\n") {
  digitalWrite(led, LOW);
  inData == "";
  }
}
