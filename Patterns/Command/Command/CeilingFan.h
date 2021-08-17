#pragma once
#include <iostream>
using namespace std;
class CeilingFan {
	int speed = 0;
public:
	static enum {
		HIGH = 3,
		MEDIUM = 2,
		LOW = 1,
		OFF = 0
	};
	void high() { 
		speed = HIGH;
		cout << "Ceiling fan speed " << speed << endl;
	}
	void medium() { 
		speed = MEDIUM; 
		cout << "Ceiling fan speed " << speed << endl;
	}
	void low() { 
		speed = LOW; 
		cout << "Ceiling fan speed " << speed << endl;
	}
	void off(){
		speed = OFF;
		cout << "Ceiling fan off" << endl;
	}
	const int getSpeed() { return speed; }
};