#include "MyBitString.h"
#include <iostream>
#include <fstream>
using namespace std;

void MyBitString::mas_from_string(string str) { 
	char tmp;
	len = str.length(); 
	mas = new unsigned char[len]; 
	for (int j = 0; j < len; j++) mas[j] = '0';
	int i = 0;
	tmp = str[i];
	while (tmp != '\0') {
		if ((tmp != '0') && (tmp != '1')) {
			cout << "Incorrect input" << endl;
			exit(0);
		}
		mas[i] = (unsigned char)tmp;
		tmp = str[++i];
	}
}

MyBitString::MyBitString() {
	mas = 0;
	len = 0;
}

MyBitString::MyBitString(string inp_str) {
	mas_from_string(inp_str);
}

MyBitString::MyBitString(const MyBitString& b) {
	len = b.len;
	mas = new unsigned char[len];
	for (int i = 0; i < len; i++) mas[i] = b.mas[i];
}

MyBitString::~MyBitString() {
	delete[]mas;
}

void MyBitString::inp() {
	string inp_str;
	getline(cin, inp_str);
	if (mas) delete[] mas;
	mas_from_string(inp_str);
}

void  MyBitString::f_inp(string filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		cout << "Unable to open file" << endl;
		exit(0);
	}
	string str;
	getline(file, str);
	if (mas) delete[] mas;
	mas_from_string(str);
	file.close();
}

void  MyBitString::outp() {
	for (int j = 0; j < len; j++)
		cout << mas[j];
	cout << endl;
}

void MyBitString::f_outp(string filename) {
	ofstream file(filename);
	if (!file.is_open()) {
		cout << "Unable to open file" << endl;
		exit(0);
	}
	for (int j = 0; j < len; j++) file << mas[j];
	file.close();
}

MyBitString& MyBitString::conjunction_r(const MyBitString& b, int len) const{ //const method gets const reference, returns reference
																			  // b defines const as b not change inside method
	int al = this->len - 1;
	int bl = b.len - 1;
	char* tmp = new char[len + 1];
	for (int i = 0; i < len; i++) {
		if ((al - i >= 0) && (bl - i >= 0))
			if ((mas[al - i] == '1') && (b.mas[bl - i] == '1')) tmp[len - 1 - i] = '1';
			else tmp[len - 1 - i] = '0';
		else tmp[len - 1 - i] = '0';
	}
	tmp[len] = '\0';
	string str = string(tmp);
	delete[]tmp;
	int found = str.find("1");
	if (found != std::string::npos) {
		str = str.substr(found);
	}
	else str = "0";
	MyBitString* res = new MyBitString(str); //create new MyBitString, get pointer
	return *res; //dereference pointer
}

MyBitString& MyBitString::conjunction(const MyBitString& b) const{ //const method gets const reference, returns reference
	if (len > b.len) return conjunction_r(b, b.len);
	else return conjunction_r(b, len);
}

MyBitString& MyBitString::operator=(const MyBitString& x) { // x defines const as x not change inside method
	if (&x == this) {return *this;} //check self copying
	if (mas) delete[] mas; //if this->mas exists delete mas
	len = x.len; //this->len=x.len
	mas = new unsigned char[len]; //allocate dynamic memory
	for (int i = 0; i < len; i++) mas[i] = x.mas[i]; //copying mas items
	return *this; //dereference pointer
}

unsigned char& MyBitString::operator[](int i) {
	unsigned char error = -1;
	if ((i < 0) || (i > len)) return error; //if i out of bounds return error
	return mas[len-i-1]; //reverse bit numbers
}

MyBitString& operator& (const MyBitString& a, const MyBitString& b) { //a and b defines const as they not change inside method
	return a.conjunction(b); //method conjunction must be const
}

ostream& operator<<(ostream& out, const MyBitString& a) {
	for (int i = 0; i < a.len; i++) out << a.mas[i]; //put all items into out
	return out; 
}

istream& operator>>(istream& in, MyBitString& a) {
	string inp_str;
	getline(in, inp_str); //get line from in
	if (a.mas) delete[] a.mas; //if this->mas exists, delete this->mas
	a.mas_from_string(inp_str); //call method
	return in;
}