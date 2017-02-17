//ORP

void orp() {

  if (input_string_complete == true && orpInput == true) {  //if a string has been received and orp was selected send to sensor
    Serial2.print(inputstring);
    Serial2.print('\r');
    inputstring = "";
    input_string_complete = false;
    }

    if (Serial2.available() > 0) {
    char inchar = (char)Serial2.read();
    orpString += inchar;
    if (inchar == '\r') {
    orp_string_complete = true;
    }
  }

  if (orp_string_complete == true) {
    Serial.println(orpString);
    /*if (isdigit(orpString[0])) {
      ORP = orpString.toFloat();
      if (ORP >= 500.0) {
        Serial.println("high");
      }
      if (ORP <= 499.9) {
        Serial.println("low");
      }
    }*/
  }
  orpString = "";
  orp_string_complete = false;
}
