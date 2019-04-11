//PH

void ph() {
  if (debug == false){
    
    if (Serial1.available() > 0) {
      char inchar = (char)Serial1.read();
      phString += inchar;
      
      if (inchar == '\r') {
        ph_string_complete = true;
      }
    }

  if (ph_string_complete == true) {
    Serial.println("PH " + phString);
    phString = "";
    ph_string_complete = false;
  }
  }
}
