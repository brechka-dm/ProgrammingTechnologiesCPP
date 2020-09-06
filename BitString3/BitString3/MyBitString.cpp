#include "MyBitString.h"
#include <iostream>
#include <fstream>
using namespace std;
MyBitString::MyBitString() {
	for (int j = 0; j < 8; j++) {
		mas[j] = '0';
	}
}
MyBitString::MyBitString(string inp_str) {
	char tmp;
	unsigned char tmps[8];
	for (int j = 0; j < 8; j++) tmps[j] = '0';
	int i = 0;
	tmp=inp_str[i]; //get first char from string
	while (tmp != '\0') {
		if (((tmp != '0') && (tmp != '1')) || (i >= 8)) {
			cout << "Incorrect input" << endl;
			exit(0);
		}
		tmps[i] = (unsigned char)tmp;
		tmp = inp_str[++i]; //get next char from string
	}
	i--;
	for (int j = 0; j <= i; j++) mas[7 - i + j] = tmps[j];
}
void MyBitString::inp() {
	char tmp;
	unsigned char tmps[8];
	for (int j = 0; j < 8; j++) tmps[j] = '0';
	int i = 0;
	cin.get(tmp);
	while (tmp != '\n') {
		if (((tmp != '0') && (tmp != '1')) || (i >= 8)) {
			cout << "Incorrect input" << endl;
			exit(0);
		}
		tmps[i] = (unsigned char)tmp;
		cin.get(tmp);
		i++;
	}
	i--;
	for (int j = 0; j <= i; j++) mas[7 - i + j] = tmps[j];
}
void  MyBitString::f_inp(string filename) {
	ifstream file(filename); 
	if (!file.is_open()) { 
		cout << "Unable to open file" << endl;
		exit(0);
	}
	char tmp;
	unsigned char tmps[8];
	for (int j = 0; j < 8; j++) tmps[j] = '0';
	int i = 0;
	while (file.get(tmp)) {
		if (((tmp != '0') && (tmp != '1')) || (i >= 8)) {
			cout << "Incorrect input" << endl;
			exit(0);
		}
		tmps[i] = (unsigned char)tmp;
		i++;
	}
	i--;
	for (int j = 0; j <= i; j++) mas[7 - i + j] = tmps[j];
	file.close();
}
void  MyBitString::outp() {
	for (int j = 0; j < 8; j++) 
		cout << mas[j];
	cout << endl;
}
void MyBitString::f_outp(string filename) {
	ofstream file(filename);
	if (!file.is_open()) {
		cout << "Unable to open file" << endl;
		exit(0);
	}
	for (int j = 0; j < 8; j++) file << mas[j];
	file.close();
}
MyBitString MyBitString::conjunction(MyBitString b) {
	char c[9];
	for (int j = 0; j < 8; j++) {
		if ((mas[j] == '1') && (b.mas[j] == '1')) c[j] = '1';
		else c[j] = '0';
	}
	c[8] = '\0'; //add EOL symbol to the end of line
	return MyBitString(string(c)); //use parameterized constructor to create new MyBitString
}
