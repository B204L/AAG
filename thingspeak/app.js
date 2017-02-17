var ThingSpeakClient = require('thingspeakclient'),
	client = new ThingSpeakClient(),
	SerialPort = require('serialport'),
	port = new SerialPort('/dev/ttyACM0', {
		baudRate: 9600,
		parser:SerialPort.parsers.readline("\r\n")
	}),
	array = "",
	orp = "",
	ph = "",
	ec = "";

port.on('data', onData);
port.on('open', onPortOpen);
port.on('close', onClose);

function onClose(){
	console.log("Closing then opening");
}

function onPortOpen(){
	console.log("Opened port.");
}

function onData(d)
{
	array = d.split('/r');
	orp = array[1];
	ph = array;
	ec = array[3];



	console.log(ph)
}

//to do
//somehow extract each line from onData(d)
//assign each line to its own variable
//possibly convert from string to int