//PH

void ph() {

  /*if (input_string_complete == true && phInput == true) { //if a string has been received and ph was selected send to sensor
    Serial1.print(inputstring);
    Serial1.print('\r');
    inputstring = "";
    input_string_complete = false;
    }*/
  
  if (Serial1.available() > 0) {
    char inchar = (char)Serial1.read();
    phString += inchar;
    if (inchar == '\r') {
    ph_string_complete = true;
    }
  }

  if (ph_string_complete == true) {
    Serial.println("PH " + phString);
   /* if (isdigit(phString[0])) {               //if the first character in the string is a digit
          pH = phString.toFloat();                    //convert the string to a floating point number so it can be evaluated by the Arduino
          if (pH >= 7.0) {                                //if the pH is greater than or equal to 7.0
            Serial.println("high");                       //print "high" this is demonstrating that the Arduino is evaluating the pH as a number and not as a string
          }
          if (pH <= 6.99) {                               //if the pH is less than or equal to 6.99
            Serial.println("low");                        //print "low" this is demonstrating that the Arduino is evaluating the pH as a number and not as a string
          }
      }*/
    phString = "";
    ph_string_complete = false;
  }
}
