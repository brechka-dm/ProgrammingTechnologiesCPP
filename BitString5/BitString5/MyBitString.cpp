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

MyBitString MyBitString::conjunction_r(MyBitString b, int len) {
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
	return MyBitString(str);
}

MyBitString MyBitString::conjunction(MyBitString b) {
	if (len > b.len) return conjunction_r(b, b.len);
	else return conjunction_r(b, len);

}
MyBitString& MyBitString::operator=(const MyBitString& x) { //overloading = operator
	if (mas) delete[] mas; //delete this->mas if exists
	len = x.len; // this->len=x.len
	mas = new unsigned char[len]; //allocate dynamic memory of len items
	for (int i = 0; i < len; i++) mas[i] = x.mas[i]; //copy array
	return *this; //return self
}

unsigned char& MyBitString::operator[](int i) {
	if ((i >= 0) && (i < len)) return mas[i];
	unsigned char error = -1; //error identifier
	return error; 
}

MyBitString operator&(MyBitString& a, MyBitString& b) { //overloading & operator
	return a.conjunction(b); //call inner method
}

ostream& operator<<(ostream& out, MyBitString& a) { //overloading output
	for (int j = 0; j < a.len; j++) 
		out << a.mas[j]; //put all items to ostream out
	return out; 
}
istream& operator>>(istream& inp, MyBitString& a) { //overloading input
	string inp_str;
	getline(inp, inp_str); //get string from istream inp
	if (a.mas) delete[] a.mas; //delete mas if it not null
	a.mas_from_string(inp_str); //call private method
	return(inp);
}