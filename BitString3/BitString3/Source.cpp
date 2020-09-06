#include <iostream>
#include "MyBitString.h" //including class header
using namespace std;

int main(int argc, char* argv[]) {
	MyBitString bs1, bs2; //creatong 2 bit strings
	if (argc < 3) { //check arguments count
		cout << "Not enough parameters" << endl;
		cout << "BitString a.txt b.txt c.txt" << endl;
		exit(0);
	}
	bs1.f_inp(argv[1]); //file input
	bs2.f_inp(argv[2]);
	cout << "a: ";
	bs1.outp(); //output
	cout << "b: ";
	bs2.outp();
	//cout << "Input bit string 1: ";
	//bs1.inp(); //mnaual input
	//cout << "Input bit string 2: ";
	//bs2.inp();
	cout << "Result: ";
	MyBitString bs3=bs1.conjunction(bs2); //creating new bit string as a result of conjunction
	bs3.outp(); 
	bs3.f_outp(argv[3]); //file output
}