String inputstring = "";
String phString = "";
String orpString = "";
String ecString = "";
boolean input_string_complete = false;
boolean ph_string_complete = false;
boolean orp_string_complete = false;
boolean ec_string_complete = false;
boolean phInput = false;
boolean ecInput = false;
boolean orpInput = false;
float ORP;
float pH;
int serialSwitch = 0;

void setup() {
  Serial.begin(9600); //hardware serial port (USB)
  Serial1.begin(9600); //ph rx0 tx1
  Serial2.begin(9600); //orp rx9 tx10
  Serial3.begin(9600); //ec rx7 tx8

  inputstring.reserve(10);
  phString.reserve(30);
  ecString.reserve(30);
  orpString.reserve(30);
}

void serialEvent() {
  inputstring = Serial.readStringUntil(13);
  input_string_complete = true;

    if (inputstring.substring(0,2) == "ec" && input_string_complete == true){  //switch inputstring to ec
    Serial.println("EC Probe Selected for Input");
    Serial3.println(inputstring.substring(2,13));
    inputstring = "";
    input_string_complete = false;
  }

  
    if (inputstring.substring(0,3) == "orp" && input_string_complete == true){ //switch inputstring to orp
    Serial.println("ORP Probe Selected for Input");
    Serial2.println(inputstring.substring(3,13));
    inputstring = "";
    input_string_complete = false;
  }

    if (inputstring.substring(0,2) == "ph" && input_string_complete == true){  //switch inputstring to PH
    Serial.println("pH Probe Selected For Input");
    Serial1.println(inputstring.substring(2,13));
    //Serial.println(inputstring.substring(2,13));
    inputstring = "";
    input_string_complete = false;
  }
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
orp();
delay(1000);
ph();
delay(1000);
ec();
delay(1000);
} //end loop
