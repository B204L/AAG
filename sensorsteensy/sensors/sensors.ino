String inputstring = "";
String phString = "";
String orpString = "";
String ecString = "";
boolean ph_string_complete = false;
boolean orp_string_complete = false;
boolean ec_string_complete = false;
boolean phInput = false;
boolean ecInput = false;
boolean orpInput = false;
boolean debug = false;

const byte numChars = 32;
char receivedChars[numChars];
boolean newData = false;

void setup() {
  Serial.begin(9600);  //hardware serial port (USB)   //These ports are all relevant to the TeensyLC's hardware serial
  Serial1.begin(9600); //ph rx0 tx1                   //Please refer to your own board's pinout if different
  Serial2.begin(9600); //orp rx9 tx10
  Serial3.begin(9600); //ec rx7 tx8
  
  phString.reserve(30);
  ecString.reserve(30);
  orpString.reserve(30);
}

void serialEvent1(){
  phString = Serial1.readStringUntil(13);
  ph_string_complete = true;
}

void serialEvent2(){
  orpString = Serial2.readStringUntil(13);
  orp_string_complete = true;
}

void serialEvent3(){
  ecString = Serial3.readStringUntil(13);
  ec_string_complete = true;
}

void loop() {
recvWithStartEndMarkers();                //Loop overview:
toggleSwitch();                           //recvWithStartEndMarkers() Checks to see if anything was sent over serial between <> characters
inputCommand();                           //toggleSwitch() checks if a <ph>, <orp>, or <ec> was sent thru the serial monitor, change
orp();                                    //boolean flags to appropriate sensor so that our input goes to the correct device.
delay(1000);                              //inputCommand() will then take any characters sent through serial monitor placed between <> markers,
ph();                                     //convert them to strings, then send them to Serial1, Serial2, or Serial3 depending on the sensor chosen in the
delay(1000);                              //toggleSwitch() function. These three functions are located in the 'input' file.
ec();                                     //Finally, loop through the orp(), ph(), and ec() functions that constantly read from Serial1, Serial2, and Serial3
delay(1000);                              //and print the results to Serial. Each of these functions are located in their respectively named file.
} //end loop
