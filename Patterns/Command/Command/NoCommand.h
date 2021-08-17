#pragma once
#include "Command.h"

// Null-object
class NoCommand :public Command {
public:
	void execute() override { return; };
	void undo() override { return; };
};