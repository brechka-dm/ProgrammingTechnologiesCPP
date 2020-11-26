#include <string>
#pragma once
using namespace std;
class MyBitString
{
	unsigned char* mas;
	int len;
	void mas_from_string(string str);
	MyBitString &conjunction_r(MyBitString b, int len);
public:
	void inp();
	void f_inp(string filename);
	void outp();
	void f_outp(string filename);
	MyBitString &conjunction(MyBitString b);
	MyBitString();
	MyBitString(string init_str);
	MyBitString(const MyBitString& b);
	~MyBitString();
	MyBitString& operator=(const MyBitString& x);
	unsigned char& operator[](int i);
	friend MyBitString& operator&(MyBitString& a, MyBitString& b);
	friend ostream& operator<<(ostream& out, MyBitString& a);
	friend istream& operator>>(istream& out, MyBitString& a);
};