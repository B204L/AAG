#include <SerialCommand.h>

SerialCommand sCmd;
String inputstring = "";
String sensorstring = "";  //a string to hold the data from the probe
boolean input_stringcomplete = false;
boolean sensor_stringcomplete = false;  //have we received all the data from the probe

// serial codes??
int consoleCode = 9600; 
int toolCode = 38400;

void setup() {  //setup hardware
                // put your setup code here, to run once:
  
  // console

  Serial.begin(consoleCode);    //usb serial communication
  
  // ph
  // rx/tx pins 0 1
  Serial1.begin(toolCode);
  
  // 0xygen
  Serial2.begin(toolCode);    // rx/tx pins 9 10
  
  // ppm
  Serial3.begin(toolCode);    // rx/tx pins 7 8
  
  inputstring.reserve(5);
  sensorstring.reserve(30);
  
  //setup callbacks for serialcommand commands
  sCmd.addCommand("ph on", ph_on);      //  turns ph sensor on
  sCmd.addCommand("ph off", ph_off);    //  turns ph sensor off
  sCmd.addCommand("o2 on", o2_on);      //  turns o2 sensor on
  sCmd.addCommand("o2 off", o2_off);    //  turns o2 sensor off
  sCmd.addCommand("ppm on", ppm_on);    //  turns ppm meter on
  sCmd.addCommand("ppm off", ppm_off);  //  turns ppm meter off
  sCmd.setDefaultHandler(unrecognized); //  handles commands that aren't matched (replies "wut")
  Serial.println("Ready");
}

void serialEvent() {                                                            //if the hardware serial port_0 receives a char              
               char inchar = (char)Serial.read();                               //get the char we just received
               inputstring += inchar;                                           //add it to the inputString
               if(inchar == '\r') {input_stringcomplete = true;}                //if the incoming character is a <CR>, set the flag
              }  


void serialEvent1(){                                                           //if the hardware serial port_1 receives a char 
              char inchar = (char)Serial1.read();                              //get the char we just received
              sensorstring += inchar;                                          //add it to the sensorString
              if(inchar == '\r') {sensor_stringcomplete = true;}               //if the incoming character is a <CR>, set the flag 
             }


void loop() {
  sCmd.readSerial();  //serialcommand processor
  }

void ph_on()  {
 
 if (input_stringcomplete){                                                    //if a string from the PC has been received in its entirety 
      Serial1.print(inputstring);                                              //send that string to the Atlas Scientific product
      inputstring = "";                                                        //clear the string:
      input_stringcomplete = false;                                            //reset the flag used to tell if we have received a completed string from the PC
      }

 if (sensor_stringcomplete){                                                   //if a string from the Atlas Scientific product has been received in its entierty 
      Serial.println(sensorstring);                                            //send that string to to the PC's serial monitor
      sensorstring = "";                                                       //clear the string:
      sensor_stringcomplete = false;                                           //reset the flag used to tell if we have received a completed string from the Atlas Scientific product
      }
}
    
void ph_off() {
  Serial.println("TURNING PH OFF");
    Serial3.println("Sleep");  //low power sleep mode from atlas scientific stamp
    sensorstring = "";
    sensor_stringcomplete = true;
}

void o2_on()  {
  if (input_stringcomplete){                //if a string from the PC has been received in its entirety 
      Serial2.print(inputstring);           //send that string to the Atlas Scientific product
      inputstring = "";                     //clear the string:
      input_stringcomplete = false;         //reset the flag used to tell if we have received a completed string from the PC
      }
  
if (sensor_stringcomplete){                 //if a string from the Atlas Scientific product has been received in its entierty 
      Serial.println(sensorstring);         //send that string to to the PC's serial monitor
      sensorstring = "";                    //clear the string:
      sensor_stringcomplete = false;        //reset the flag used to tell if we have received a completed string from the Atlas Scientific product
      }
 }
 
void o2_off()  {
  Serial.println("TURNING O2 OFF");
    Serial2.print("Sleep");
    sensorstring = "";
    sensor_stringcomplete = true;
}

void ppm_on()  {
  if (input_stringcomplete){                //if a string from the PC has been received in its entirety 
      Serial3.print(inputstring);           //send that string to the Atlas Scientific product
      inputstring = "";                     //clear the string:
      input_stringcomplete = false;         //reset the flag used to tell if we have received a completed string from the PC
      }
  
if (sensor_stringcomplete){                 //if a string from the Atlas Scientific product has been received in its entierty 
      Serial.println(sensorstring);         //send that string to to the PC's serial monitor
      sensorstring = "";                    //clear the string:
      sensor_stringcomplete = false;        //reset the flag used to tell if we have received a completed string from the Atlas Scientific product
      }
 }
    
void ppm_off()  {
  Serial.println("TURNING PPM OFF");
    Serial3.print("Sleep");
    sensorstring = "";
    sensor_stringcomplete = true;
  
}

void unrecognized(const char *command)  {
  Serial.println("wut");
  }
