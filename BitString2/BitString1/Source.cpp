#include <iostream>
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

int main() {
	unsigned char bs1[8]; 
	unsigned char bs2[8]; 
	unsigned char bs3[8]; 
	for (int j = 0; j < 8; j++) {
		bs1[j] = '0';
		bs2[j] = '0';
		bs3[j] = '0';
	}
	/*---input---*/
	cout << "Input bit string 1: ";
	inp(bs1);
	cout << "Input bit string 2: ";
	inp(bs2);
	/*---conjunction---*/
	conj(bs1, bs2, bs3);
	/*---output result---*/
	cout << "Result: ";
	outp(bs3);
	//r_output(bs3);
	return 0;
}