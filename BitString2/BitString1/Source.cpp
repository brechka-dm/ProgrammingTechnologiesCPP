#include <iostream>
#include <fstream> //for file streams
using namespace std;

void inp(unsigned char * res) { //input procedure 
	char tmp;
	unsigned char tmps[8];
	for (int j = 0; j < 8; j++) tmps[j] = '0';
	int i = 0;
	cin.get(tmp);
	while (tmp != '\n') {
		if (((tmp != '0') && (tmp != '1')) || (i >= 8)) {
			cout << "Incorrect input" << endl;
			exit(0); //exit all program not only subprogram
		}
		tmps[i] = (unsigned char)tmp;
		cin.get(tmp);
		i++;
	}
	i--;
	for (int j = 0; j <= i; j++) res[7 - i + j] = tmps[j];
}

void outp(unsigned char* mas) { //output procedure
	for (int j = 0; j < 8; j++) cout << mas[j];
	cout << endl;
}

void r_output(unsigned char* mas, int ind=0) { //recursive output procedure
	cout << mas[ind++];
	if (ind == 8) { //recursion exit condition
		cout << endl;
		return;
	}
	r_output(mas, ind); //recursion
}

void conj(unsigned char* a, unsigned char* b, unsigned char* c) { //conjunction - multiparameter procedure
	for (int j = 0; j < 8; j++) {
		if ((a[j] == '1') && (b[j] == '1')) c[j] = '1';
		else c[j] = '0';
	}
}

void f_input(string filename, unsigned char* res) { //file input procedure
	ifstream file(filename); //creating input filestream object
	if (!file.is_open()) { //check if file is open
		cout << "Unable to open file" << endl;
		exit(0);
	}
	char tmp;
	unsigned char tmps[8];
	for (int j = 0; j < 8; j++) tmps[j] = '0';
	int i = 0;
	while (file.get(tmp)) { //while not EOf reading nect char from stream
		if (((tmp != '0') && (tmp != '1')) || (i >= 8)) {
			cout << "Incorrect input" << endl;
			exit(0);
		}
		tmps[i] = (unsigned char)tmp;
		i++;
	}
	i--;
	for (int j = 0; j <= i; j++) res[7 - i + j] = tmps[j];
	file.close(); //close file after use
}

void f_outp(string filename,unsigned char* mas) { //output procedure
	ofstream file(filename);
	if (!file.is_open()) {
		cout << "Unable to open file" << endl;
		exit(0); //exit all program not only subprogram
	}
	for (int j = 0; j < 8; j++) file << mas[j];
	file.close();
}

int main(int argc, char* argv[]) {
	unsigned char bs1[8]; 
	unsigned char bs2[8]; 
	unsigned char bs3[8]; 
	for (int j = 0; j < 8; j++) {
		bs1[j] = '0';
		bs2[j] = '0';
		bs3[j] = '0';
	}
	/*---manual input---*/
	/*cout << "Input bit string 1: ";
	inp(bs1);
	cout << "Input bit string 2: ";
	inp(bs2);*/
	/*---file input---*/
	if (argc < 3) { //check arguments count
		cout << "Not enough parameters" << endl;
		cout << "BitString a.txt b.txt c.txt" << endl;
		exit(0);
	}
	f_input(argv[1], bs1);
	f_input(argv[2], bs2);
	/*---conjunction---*/
	conj(bs1, bs2, bs3);
	/*---console output---*/
	//cout << "Result: ";
	//outp(bs3);
	////r_output(bs3);
	/*---file output---*/
	f_outp(argv[3], bs3);
	return 0;
}