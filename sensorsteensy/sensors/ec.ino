//EC

void ec(){

    if (input_string_complete == true && ecInput == true) { //if a string has been received and orp was selected send to sensor
    Serial3.print(inputstring);
    Serial3.print('\r');
    inputstring="";
    input_string_complete = false;
    }
  
    if (Serial3.available() > 0) {
    char inchar = (char)Serial3.read();
    ecString += inchar;
    if (inchar == '\r') {
    ec_string_complete = true;
    }
  }

  if (ec_string_complete == true) {
    if (isdigit(ecString[0]) == false) {
      Serial.println(ecString);
    }
    else
    {
      print_EC_data();
    }
    ecString = "";
    ec_string_complete = false;
  }
}

void print_EC_data(void) {                            //this function will pars the string  

  char ecString_array[30];                        //we make a char array
  char *EC;                                           //char pointer used in string parsing
  char *TDS;                                          //char pointer used in string parsing
  char *SAL;                                          //char pointer used in string parsing
  char *GRAV;                                         //char pointer used in string parsing
  //float f_ec;                                         //used to hold a floating point number that is the EC
  
  ecString.toCharArray(ecString_array, 30);   //convert the string to a char array 
  EC = strtok(ecString_array, ",");               //let's pars the array at each comma
  TDS = strtok(NULL, ",");                            //let's pars the array at each comma
  SAL = strtok(NULL, ",");                            //let's pars the array at each comma
  GRAV = strtok(NULL, ",");                           //let's pars the array at each comma

  Serial.print("EC ");                                //we now print each value we parsed separately
  Serial.println(EC);                                 //this is the EC value

  //Serial.print("TDS:");                               //we now print each value we parsed separately
  //Serial.println(TDS);                                //this is the TDS value

  //Serial.print("SAL:");                               //we now print each value we parsed separately
  //Serial.println(SAL);                                //this is the salinity value

  //Serial.print("GRAV:");                              //we now print each value we parsed separately
  //Serial.println(GRAV);                               //this is the specific gravity
  //Serial.println();                                   //this just makes the output easier to read
  
//f_ec= atof(EC);                                     //uncomment this line to convert the char to a float
}

