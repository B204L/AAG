var ThingSpeakClient = require('thingspeakclient'),
	client = new ThingSpeakClient(),
	SerialPort = require('serialport'),
	port = new SerialPort('/dev/ttyACM0', {
		baudRate: 9600,
		parser:SerialPort.parsers.readline("\r\n")
	}),
	ORP = "",
	PH = "",
	EC = "";

port.on('data', onData);
port.on('open', onPortOpen);
port.on('close', onClose);

client.attachChannel(241532, { writeKey:'9YDKF4SZJKM60JDW', readKey:'4YJMH1Y46NXRWQQ9'});	//thingspeak client connect API keys

function onClose(){	//lets you know the port is closed
	console.log("Closing then opening");
}

function onPortOpen(){	//lets you know the port is open
	console.log("Opened port.");
}

function onData(d)	//loop reads sensor string from /dev/ttyACM0 and parses it for each reading, then updates thingspeak channel
{
	if (d.substr(0,3) == "ORP"){
		ORP = d.substr(4,9);
		//console.log(ORP);	//for debugging
	}

	if (d.substr(0,2) == "EC"){
		EC = d.substr(3,6);
		//console.log(EC);
	}

	if (d.substr(0,2) == "PH"){
		PH = d.substr(3,6);
		//console.log(PH);
	}

	client.updateChannel(241532, {field1: PH, field2: ORP, field3: EC}, function(err, resp){
		if (!err && resp > 0) {
			console.log('Update succesfull. Entry number was: ' + resp);
		}
	});
}