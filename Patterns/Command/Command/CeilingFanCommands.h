#pragma once
#include "Command.h"
#include "CeilingFan.h"

void setUndo(shared_ptr<CeilingFan> ceilingFan, int prevSpeed) {
	switch (prevSpeed) {
	case CeilingFan::HIGH:
		ceilingFan->high();
		break;
	case CeilingFan::MEDIUM:
		ceilingFan->medium();
		break;
	case CeilingFan::LOW:
		ceilingFan->low();
		break;
	case CeilingFan::OFF:
		ceilingFan->off();
		break;
	}
}

class CeilingFanHighCommand : public Command {
	shared_ptr<CeilingFan> ceilingFan;
	int prevSpeed;
public:
	CeilingFanHighCommand(shared_ptr<CeilingFan> ceilingFan) { this->ceilingFan = ceilingFan; }
	void execute() override {
		prevSpeed = ceilingFan->getSpeed();
		ceilingFan->high();
	}
	void undo() {
		setUndo(ceilingFan, prevSpeed);
	}
};

class CeilingFanMediumCommand : public Command {
	shared_ptr<CeilingFan> ceilingFan;
	int prevSpeed;
public:
	CeilingFanMediumCommand(shared_ptr<CeilingFan> ceilingFan) { this->ceilingFan = ceilingFan; }
	void execute() override {
		prevSpeed = ceilingFan->getSpeed();
		ceilingFan->medium();
	}
	void undo() {
		setUndo(ceilingFan, prevSpeed);
	}
};

class CeilingFanOffCommand : public Command {
	shared_ptr<CeilingFan> ceilingFan;
	int prevSpeed;
public:
	CeilingFanOffCommand(shared_ptr<CeilingFan> ceilingFan) { this->ceilingFan = ceilingFan; }
	void execute() override {
		prevSpeed = ceilingFan->getSpeed();
		ceilingFan->off();
	}
	void undo() {
		setUndo(ceilingFan, prevSpeed);
	}
};