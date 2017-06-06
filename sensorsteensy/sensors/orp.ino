//ORP

void orp() {

  if (debug == false){

    if (Serial2.available() > 0) {
    char inchar = (char)Serial2.read();
    orpString += inchar;
    
    if (inchar == '\r') {
    orp_string_complete = true;
    }
  }

  if (orp_string_complete == true) {
    Serial.println("ORP " + orpString);
  }
  orpString = "";
  orp_string_complete = false;
  }
}
