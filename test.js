    //dependencies
var five = require("johnny-five"),
	express = require("express"),
	jade = require("jade"),
	stylus = require("stylus"),
    board = new five.Board(),
    //global function variables
    ph = new five.Sensor.Digital(2),
    ec = new five.Sensor.Digital(3),
    o2 = new five.Sensor.Digital(4),
    pump1 = new five.Stepper({
    	type: five.Stepper.TYPE.DRIVER,
    	stepsPerRev: 200,
    	pins: [0, 1]
    	});
    pump2 = new five.Stepper({
    	type: five.Stepper.TYPE.DRIVER,
    	stepsPerRev: 200,
    	pins: [2, 3]
    	});
    feeder = new five.Stepper({
    	type: five.Stepper.TYPE.DRIVER,
    	stepsPerRev: 200,
    	pins: [4, 5]
    light = true;

board.on("ready", function() {
  // Create an Led on pin 13
  var led = new five.Led(13);

  // Strobe the pin on/off, defaults to 100ms phases
  led.strobe();
});

//pH digital sensor

  var sensor = new five.Sensor.Digital(2);

  sensor.on("change", function() {
    console.log(this.value);
  });
});

//EC digital sensor

board.on("ready", function() {

  var sensor = new five.Sensor.Digital(2);

  sensor.on("change", function() {
    console.log(this.value);
  });
});

//o2 digital sensor

board.on("ready", function() {

  var sensor = new five.Sensor.Digital(2);

  sensor.on("change", function() {
    console.log(this.value);
  });
});

//water temperature sensor

new five.Thermometer({
	controller: "DS18B20",
	pin: "A1"
});

//feeder hopper stepper motor
function feed() {
	console.log("Running 1 feeding cycle");
	feeder.step({
		steps: 2000, //10 full revolutions (200 step motor)
		direction: 1, //clockwise (0 is ccw)
		accel: 1600, //accelerate over first 1600 steps
		decel: 1600 //decelerate over last 1600 steps
		},
		function() {
			console.log("Finished feeding!");
		});
}

function dose1() {
	console.log("Running 1 dosing cycle");
	pump1.step({
		steps: 2000, //10 full revolutions (200 step motor)
		direction: 1, //clockwise (0 is ccw)
		accel: 1600, //accelerate over first 1600 steps
		decel: 1600 //decelerate over last 1600 steps
		},
		function() {
			console.log("Finished!");
		});
}

function dose2() {
	console.log("Running 1 dosing cycle");
	pump2.step({
		steps: 2000, //10 full revolutions (200 step motor)
		direction: 1, //clockwise (0 is ccw)
		accel: 1600, //accelerate over first 1600 steps
		decel: 1600 //decelerate over last 1600 steps
		},
		function() {
			console.log("Finished!");
		});
}