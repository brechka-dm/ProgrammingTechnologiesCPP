#include "RemoteControl.h"
#include "Light.h"
#include "Stereo.h"
#include "CeilingFan.h"
#include "LightCommands.h"
#include "StereoCommands.h"
#include "CeilingFanCommands.h"


// Command pattern CLIENT
int main() {
	unique_ptr<RemoteControl> remote = make_unique<RemoteControl>(); // Command pattern INVOCER

	// Command pattern RECEIEVERS
	shared_ptr<Light> livingRoomLight = make_shared<Light>();
	shared_ptr<Light> bedRoomLight = make_shared<Light>();
	shared_ptr<CeilingFan> bedRoomCeilingFan = make_shared<CeilingFan>();
	shared_ptr<Stereo> stereo = make_shared<Stereo>();
	
	// Command pattern COMMANDS
	shared_ptr<LightOnCommand> livingRoomLightOn = make_shared<LightOnCommand>(livingRoomLight);
	shared_ptr<LightOffCommand> livingRoomLightOff = make_shared<LightOffCommand>(livingRoomLight);

	shared_ptr<LightOnCommand> bedRoomLightOn = make_shared<LightOnCommand>(bedRoomLight);
	shared_ptr<LightOffCommand> bedRoomLightOff = make_shared<LightOffCommand>(bedRoomLight);

	shared_ptr<CeilingFanMediumCommand> ceilingFanMedium = make_shared<CeilingFanMediumCommand>(bedRoomCeilingFan);
	shared_ptr<CeilingFanHighCommand> ceilingFanHigh = make_shared<CeilingFanHighCommand>(bedRoomCeilingFan);
	shared_ptr<CeilingFanOffCommand> ceilingFanOff = make_shared<CeilingFanOffCommand>(bedRoomCeilingFan);

	shared_ptr<StereoOnWithCDCommand> stereoCD = make_shared<StereoOnWithCDCommand>(stereo);
	shared_ptr<StereoOnWithRadioCommand> stereoRadio = make_shared<StereoOnWithRadioCommand>(stereo);
	shared_ptr<StereoOffCommand> stereoOff = make_shared<StereoOffCommand>(stereo);

	// Setting commands to invocer
	remote->setCommand(0, livingRoomLightOn, livingRoomLightOff);
	remote->setCommand(1, bedRoomLightOn, bedRoomLightOff);
	remote->setCommand(2, ceilingFanMedium, ceilingFanOff);
	remote->setCommand(3, ceilingFanHigh, ceilingFanOff);
	remote->setCommand(4, stereoCD, stereoOff);
	remote->setCommand(5, stereoRadio, stereoOff);

	// Executing commands
	remote->onButtonPress(0);
	remote->offButtonPress(0);
	remote->undoButtonPress();

	remote->onButtonPress(2);
	remote->offButtonPress(2);
	remote->undoButtonPress();

	remote->onButtonPress(5);
	remote->offButtonPress(5);
	remote->undoButtonPress();

	return 0;
}