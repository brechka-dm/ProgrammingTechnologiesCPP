#include <string>
#pragma once
using namespace std;
class MyBitString
{
	unsigned char* mas; //pointer to array
	int len; //array length
	void mas_from_string(string str); //private method
public:
	void inp(); //manual input
	void f_inp(string filename); //file input
	void outp(); //console output
	void f_outp(string filename); //file output
	MyBitString& conjunction(const MyBitString& b) const; 
	MyBitString& conjunction_r(const MyBitString& b, int len) const;
	MyBitString(); //default constructor
	MyBitString(string init_str); //init constructor
	MyBitString(const MyBitString& b); //copy constructor
	~MyBitString(); //destructor
	MyBitString& operator=(const MyBitString& x); //overloading = as method
	unsigned char& operator[](int i);  //overloading [] as method
	friend MyBitString& operator& (const MyBitString& a, const MyBitString& b);  //overloading & as friend function
	friend ostream& operator<<(ostream& out, const MyBitString& a); //overloading << as friend function
	friend istream& operator>>(istream& in, MyBitString& a); //overloading >> as friend function
};