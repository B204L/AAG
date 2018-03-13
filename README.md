# AAG
Control program using Atlas-Scientific sensors for monitoring water quality

# C# / Low Level side

Sensor stamps are connected over UART to a microcontroller of your choice (Teensy LC in my case) where incoming data is sent as a string and assigned to variables, then output through the serial monitor and attached oled display. Not an elegant solution but it hasn't crashed from heap fragmentation so far.

Strings can be received from the serial monitor, received strings will need to be between start and end markers like so: `<STRING>`

To send a command to an individual sensor it will first need to be selected by sending `<PH>` `<EC>` or `<ORP>` through the serial monitor. Once selected it can receive UART commands, see Atlas-Scientific documentation for specific commands in regards to each particular stamp.

There's also a simple debug mode that will halt all sensor readings to the output to make it easier to read, use `<debug>` to enter this mode and twice to exit it and resume output.

# Node JS

A simple Node JS app using the Johnny-Five library receives the data from the sensors over the /dev/ttyACM0 port and uploads them to a ThingSpeak account. The method for this not only uses strings but calls on the substr method to parse through the incoming string and assigns only the number portion to a variable (which is then uploaded to ThingSpeak). This is handy for documentation and observation of your water's status over the internet.

# To Do

- Get off of string dependency and use char arrays instead
- Work on a solution for a nicer breakout board, breadboards and jumper wires are messy
- More research into relays and peristaltic pumps for nutrient dosing
