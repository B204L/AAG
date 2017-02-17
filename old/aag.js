/**
 * @author justin
 */
var app = require('express')()                     //dependencies
, server = require('http').createServer(app)
, io = require('socket.io').listen(server)
, SerialPort  = require('serialport').SerialPort;

var sensors = ""

var serialPath = '/dev/ttyACM0';                   //path to serial port on Raspberry Pi (where the arduino is sending shit)
var serialPort = new SerialPort(serialPath, {         //creates new SerialPort named sensors object with serialPath
	baudRate: 115200,
	dataBits: 8,
	parity: 'none',
	stopBits: 1,
	flowControl: false
}); 

serialPort.on("open", function() {                  //wait for the 'open' event before reading / writing to serial port
	console.log('open');
	serialPort.on('data', function(data) {
		console.log('data received: ' + data);
	});
	serialPort.read()                               //when it's open, read the serial port
	parser: serialport.parsers.readline("\n")       //parse the incoming string delimited by new lines
});