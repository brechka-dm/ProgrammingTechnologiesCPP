#include <iostream>
using namespace std;
int main() {
	unsigned char bs1[8]; //bit string 1
	unsigned char bs2[8]; //bit string 2
	unsigned char bs3[8]; //result
	for (int j = 0; j < 8; j++) { //put '0' to all bits
		bs1[j] = '0';
		bs2[j] = '0';
		bs3[j] = '0';
	}
	/*---bit string 1 input---*/
	cout << "Input bit string 1: ";
	char tmp; //temp char
	unsigned char tmps[8]; //temp bit string
	for (int j = 0; j < 8; j++) tmps[j] = '0'; //put '0' to all bits 
	int i = 0; //bit counter
	cin.get(tmp); //get one char from console
	while (tmp != '\n') { //while not EOL
		if (((tmp != '0') && (tmp != '1')) || (i >= 8)) { //if char is not '1' and not '0' or bit count > 8
			cout << "Incorrect input" << endl; 
			return 1; //exit program
		}
		tmps[i] = (unsigned char)tmp; //put char to tmps on place i
		cin.get(tmp); //get next char
		i++; //increment bit counter
	}
	i--; //one extra char was read
	for (int j = 0; j <=i; j++) bs1[7 - i+j] = tmps[j]; //shifting data from tmps to bs1
	/*---bit string 2 input---*/
	cout << "Input bit string 2: ";
	for (int j = 0; j < 8; j++) tmps[j] = '0';
	i = 0;
	cin.get(tmp);
	while (tmp != '\n') {
		if (((tmp != '0') && (tmp != '1')) || (i >= 8)) {
			cout << "Incorrect input" << endl;
			return 1;
		}
		tmps[i] = (unsigned char)tmp;
		cin.get(tmp);
		i++;
	}
	i--;
	for (int j = 0; j <= i; j++) bs2[7 - i+j] = tmps[j];
	/*---conjunction---*/
	for (int j = 0; j < 8; j++) {
		if ((bs1[j] == '1') && (bs2[j] == '1')) bs3[j] = '1';
		else bs3[j] = '0';
	}
	/*---output result---*/
	cout << "Result: ";
	for (int j = 0; j < 8; j++) cout << bs3[j];
	cout << endl;
	return 0;
}