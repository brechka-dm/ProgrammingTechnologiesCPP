#include <iostream>
#include "MyBitString.h"
using namespace std;

int main(int argc, char* argv[]) {
	MyBitString bs1, bs2;
	if (argc < 3) { 
		cout << "Not enough parameters" << endl;
		cout << "BitString a.txt b.txt c.txt" << endl;
		exit(0);
	}
	bs1.f_inp(argv[1]);
	bs2.f_inp(argv[2]);
	cout << "a: ";
	bs1.outp();
	cout << "b: ";
	bs2.outp();
	cout << "Result: ";
	MyBitString bs3 = bs1.conjunction(bs2);
	bs3.outp();
	bs3.f_outp(argv[3]);
}