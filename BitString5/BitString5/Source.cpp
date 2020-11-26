#include "MyBitString.h"
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char* argv[]) {
	MyBitString a, b, c;
	if (argc < 4) { //manual input if not enough file arguments
		cout << "Input bit string 1: ";
		cin >> a; //overloaded input
		cout << "Input bit string 2: ";
		cin >> b;
		c = a & b; //overloaded &
		cout << c << endl; //overloaded output
	}
	else { //file input and output
		a.f_inp((const char*)argv[1]); //argv[1] - a.txt
		b.f_inp((const char*)argv[2]); //argv[2] - b.txt
		c = a & b;
		c.f_outp((const char*)argv[3]); //argv[3] - c.txt
	}
}