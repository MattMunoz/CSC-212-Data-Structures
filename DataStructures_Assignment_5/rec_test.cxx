/*
	NAME: Matthew Munoz
	Emp ID: 0663
	“The work in this assignment is my own. Any outside sources have been properly cited.”
*/

#include <iostream>
#include "rec_fun.h"
using namespace M_munoz_05; 
using namespace std;

int main()
{
	cout << "----------BINARY PRINT----------";
	cout << endl << "n=0" << "\tOutput: ";
	binary_print(cout, 0);
	cout << endl << "n=4" << "\tOutput: ";
	binary_print(cout, 4);
	cout << endl << "n=27" << "\tOutput: ";
	binary_print(cout, 27);
	cout << endl << "n=64" << "\tOutput: ";
	binary_print(cout, 64);
	cout << "\n\n\n";

	cout << "----------TRIANGLR----------" << endl;
	triangle(cout, 5, 5);
	cout << endl;
	triangle(cout, 0, 6);
	cout << endl;
	triangle(cout, 9, 7);
	cout << "\n\n";

	cout << "----------POW----------" << endl;
	cout << "2^2: \t" <<  power(2, 2) << endl;
	cout << "5^2: \t" << power(5, 2) << endl;
	cout << "9^3: \t" << power(9, 3) << endl;
	cout << "3^(-1): " << power(3, -1) << endl;
	cout << "\n\n";

	cout << "----------INDENTED SCENTENCE----------" << endl;
	indented_sentences(1, 4);
	cout << endl;
	indented_sentences(10, 3);
}