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
		if ((tmp != '0') && (tmp != '1')) throw runtime_error("Incorrect symbol found");  //throw runtime_error
		mas[i] = (unsigned char)tmp;
		tmp = str[++i];
	}
}

MyBitString::MyBitString() {mas = 0;len = 0;}

MyBitString::MyBitString(string inp_str) {mas_from_string(inp_str);}

MyBitString::MyBitString(const MyBitString& b) {
	len = b.len;
	mas = new unsigned char[len];
	for (int i = 0; i < len; i++) mas[i] = b.mas[i];
}

MyBitString::~MyBitString() {delete[]mas;}

void MyBitString::inp() {
	string inp_str;
	getline(cin, inp_str);
	if (mas) delete[] mas;
	mas_from_string(inp_str);
}

void  MyBitString::f_inp(string filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		throw runtime_error("Unable to open file");  //throw runtime_error
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
		throw runtime_error("Unable to open file");  //throw runtime_error
	}
	for (int j = 0; j < len; j++) file << mas[j];
	file.close();
}

MyBitString& MyBitString::conjunction_r(MyBitString b, int len) {
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
	MyBitString* res=new MyBitString(str);
	return *res;
}

MyBitString& MyBitString::conjunction(MyBitString b) {
	if (len > b.len) return conjunction_r(b, b.len);
	else return conjunction_r(b, len);

}
MyBitString& MyBitString::operator=(const MyBitString& x) {
	if (mas) delete[] mas;
	len = x.len;
	mas = new unsigned char[len];
	for (int i = 0; i < len; i++) mas[i] = x.mas[i];
	return *this;
}

unsigned char& MyBitString::operator[](int i) {
	if ((i >= 0) && (i < len)) return mas[len-i-1];
	else throw runtime_error("Index out of bouds");  //throw runtime_error
}

MyBitString& operator&(MyBitString& a, MyBitString& b) { return a.conjunction(b);}

ostream& operator<<(ostream& out, MyBitString& a) {
	for (int j = 0; j < a.len; j++)
		out << a.mas[j];
	return out;
}
istream& operator>>(istream& inp, MyBitString& a) {
	string inp_str;
	getline(inp, inp_str);
	if (a.mas) delete[] a.mas;
	a.mas_from_string(inp_str);
	return(inp);
}