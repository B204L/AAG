# AAG
Ardunion sensor controller logic for TEENSY LC board

I think we are using [this](https://github.com/kroimon/Arduino-SerialCommand)

### testing
I found this emulator called emulion we can use for testing

```
sudo apt-get install arduino arduino-core  
git clone git://github.com/ghewgill/emulino.git
cd emulino/
sudo apt-get install scons # idk what this is but it uses this to build/make
vim SConstruct # this is like the make file needs editing see below
scons
```

## changes to SConstruct
I had to change the python path from `/opt/bin/some/crap/python` to `/usr/bin/python` and then also removed -Werror from the C compiler flags but it should be good then

## arduino IDE
Are you using this?  I can't get the code to compile throwing errors on every Serial call...
