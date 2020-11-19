#include "MyBitString.h"
#include <iostream>
#include <fstream>
using namespace std;

void MyBitString::mas_from_string(string str) { //private method
	char tmp;
	len = str.length(); //get str length
	mas = new unsigned char[len]; //dynamic memory allocation
	for (int j = 0; j < len; j++) mas[j] = '0'; //initialization
	int i = 0;
	tmp = str[i]; 
	while (tmp != '\0') {
		if ((tmp != '0') && (tmp != '1')) { //check for incorrect symbols
			cout << "Incorrect input" << endl;
			exit(0);
		}
		mas[i] = (unsigned char)tmp; //put char from str to mas
		tmp = str[++i];
	}
}

MyBitString::MyBitString() {
	mas = 0;
	len = 0;
}

MyBitString::MyBitString(string inp_str) {
	mas_from_string(inp_str); //call private metod
}

MyBitString::MyBitString(const MyBitString& b) {
	len = b.len; 
	mas = new unsigned char[len]; //dynamic memory allocation
	for (int i = 0; i < len; i++) mas[i] = b.mas[i]; //copy items from b.mas to this->mas
}

MyBitString::~MyBitString() {
	delete[]mas; //free dynamic memory
}

void MyBitString::inp() {
	string inp_str;
	getline(cin, inp_str); //get string from cin
	if (mas) delete[] mas; //delete mas if it not null
	mas_from_string(inp_str); //call private method
}

void  MyBitString::f_inp(string filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		cout << "Unable to open file" << endl;
		exit(0);
	}
	string str;
	getline(file, str); //get strig from file
	if (mas) delete[] mas; //delete mas if it not null
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
	int al = this->len-1;
	int bl = b.len-1;
	char* tmp = new char[len+1]; //allocate new char mas (len+1 for '\0')
	for (int i = 0; i < len; i++) {
		if((al-i>=0)&&(bl-i>=0)) //there is item in A and item in B
			if ((mas[al-i] == '1') && (b.mas[bl-i] == '1')) tmp[len-1-i] = '1';
			else tmp[len-1-i] = '0';
		else tmp[len-1-i] = '0';
	}
	tmp[len] = '\0';
	string str = string(tmp);
	delete[]tmp;
	int found = str.find("1");
	if (found != std::string::npos) {
		str = str.substr(found);
	}
	else str = "0";
	return MyBitString(str); //call cinstructor
}

MyBitString MyBitString::conjunction(MyBitString b) {
	if (len > b.len) return conjunction_r(b, b.len); //call conjunction_r with minimum length
	else return conjunction_r(b, len);
	
}