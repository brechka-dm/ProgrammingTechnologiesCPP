#include <string>
#pragma once //to include only one time
using namespace std;
class MyBitString
{
	unsigned char mas[8]; //private member
public:
	void inp(); //manual input method
	void f_inp(string filename); //file input method
	void outp(); //console output method
	void f_outp(string filename); //file output method
	MyBitString conjunction(MyBitString b); //result of a conjunction is a new bit string
	MyBitString(); //default construcor
	MyBitString(string init_str); //parameterized constructor
};

