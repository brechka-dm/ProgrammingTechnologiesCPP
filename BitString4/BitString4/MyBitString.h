#include <string>
#pragma once
using namespace std;
class MyBitString
{
	unsigned char* mas;
	int len; //to store mas length
	void mas_from_string(string str); //private method
public:
	void inp();
	void f_inp(string filename);
	void outp();
	void f_outp(string filename);
	MyBitString conjunction(MyBitString b);
	MyBitString conjunction_r(MyBitString b, int len); //length limited conjunction
	MyBitString();
	MyBitString(string init_str);
	MyBitString(const MyBitString &b); //copy constructor
	~MyBitString(); //destructor
};

