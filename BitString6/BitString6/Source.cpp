#include "MyBitString.h"
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char* argv[]) {
	MyBitString a, b, c;
	try {
		if (argc < 4) { 
			cout << "Input bit string 1: ";
			cin >> a;
			cout << "Input bit string 2: ";
			cin >> b;
			c = a & b;
			cout << c << endl;
		}
		else {
			a.f_inp((const char*)argv[1]);
			b.f_inp((const char*)argv[2]);
			c = a & b;
			c.f_outp((const char*)argv[3]);
		}
	}
	catch (const runtime_error &a) {
		cout << "Exception: "<<a.what();
	}
}