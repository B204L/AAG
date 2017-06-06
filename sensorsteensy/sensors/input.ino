void recvWithStartEndMarkers() {                                 //Receive with start and end markers <>
    static boolean recvInProgress = false;                       //Anything send thru serial monitor will
    static byte ndx = 0;                                         //only be read if between <> (e.g. qwer<asdf>wer only reads 'asdf')
    char startMarker = '<';                                      //http://forum.arduino.cc/index.php?topic=396450
    char endMarker = '>';
    char rc;
 
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (recvInProgress == true) {
            if (rc != endMarker) {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars) {
                    ndx = numChars - 1;
                }
            }
            else {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        }

        else if (rc == startMarker) {
            recvInProgress = true;
        }
    }
}

void toggleSwitch() {
    
    if (newData == true && (strcmp(receivedChars,"ph") == 0)){  //Comparison operator to detect if 
        Serial.println("PH Selected");                          //specific char array was sent, "ph" in this case.
        phInput = true;                                         //Flags for choosing between sensors,
        orpInput = false;                                       //if <ph> was sent through serial monitor
        ecInput = false;                                        //compare received char to "ph" string then
        newData = false;                                        //set all boolean values appropriately.
    }                                                           //This function exists so that we can send commands
                                                                //to different sensors at different serial ports.
    if (newData == true && (strcmp(receivedChars,"ec") == 0)){
        Serial.println("EC Selected");                          //Find all relevant UART commands here:
        phInput = false;                                        //https://www.atlas-scientific.com/
        orpInput = false;                                       //e.g. sending <C,0> will disable continuous reading and is read as: 'C,0' without quotes
        ecInput = true;                                         //<C,1> will re-enable continuous reading and is read as: 'C,1' without quotes
        newData = false;
    }

    if (newData == true && (strcmp(receivedChars,"orp") == 0)){
        Serial.println("ORP Selected");
        phInput = false;
        orpInput = true;
        ecInput = false;
        newData = false;
    }

    if (newData == true && (strcmp(receivedChars,"debug") == 0)){ //Stops sensor readings for convenience while
      Serial.println("Debug mode toggled");                       //working in serial monitor. Send <debug> to toggle.
      debug = !debug;
      newData = false;
    }
}

void inputCommand(){
                                                                //This function will send commands to the 
                                                                //sensor chosen in the toggleSwitch function.
    inputstring = receivedChars;                                //Convert char array to string cause
                                                                //AtlasScientific stuff reads strings only.
    if (newData == true && phInput == true){                    //If data is received thru serial monitor and
        Serial1.print(inputstring);                             //ph sensor is selected,
        Serial1.print('\r');                                    //then send input to Serial1 (pH in my case).
        Serial.println("pH Input Received");
        newData = false;
    }

    if (newData == true && orpInput == true){
        Serial2.print(inputstring);
        Serial2.print('\r');
        Serial.println("ORP Input Received");
        newData = false;
    }

    if (newData == true && ecInput == true){
        Serial3.print(inputstring);
        Serial3.print('\r');
        Serial.println("EC Input Received");
        newData = false;
    }
}
