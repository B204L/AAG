//EC

void ec(){

  if (debug == false){
  
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
    
  else{
    print_EC_data();
  }
  ecString = "";
  ec_string_complete = false;
  }
  }
}

void print_EC_data(void) {                    //this function will parse the string  

  char ecString_array[30];                    //we make a char array
  char *EC;                                   //char pointer used in string parsing
  //float f_ec;                               //used to hold a floating point number that is the EC
  
  ecString.toCharArray(ecString_array, 30);   //convert the string to a char array 
  EC = strtok(ecString_array, ",");           //let's parse the array at each comma
  Serial.print("EC ");                        //we now print each value we parsed separately
  Serial.println(EC);                         //this is the EC value
  //Serial.println();                         //this just makes the output easier to read
  
//f_ec= atof(EC);                             //uncomment this line to convert the char to a float
}

