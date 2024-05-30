/*
	NAME: Matthew Munoz
	Emp ID: 0663
	“The work in this assignment is my own. Any outside sources have been properly cited.”

	//FUNCTIONS
	void binary_print(ostream& outs, unsigned int n)
	// Precondition: n > 0
	// Postcondition: The binary value of the given interger is printed to the console 

	void triangle(ostream& outs, unsigned int m, unsigned int n)
	// Precondition: m <= n
	// Postcondition: The function has printed a pattern of 2*(n-m+1) lines
	// to the output stream outs. The first line contains m asterisks, the next 
	// line contains m+1 asterisks, and so on up to a line with n asterisks.
	// Then the pattern is repeated backwards, going n back down to m.

	double pow(double x, int n);
	// Precondition: If x is zero, then n must be positive. 
	// Precondition: If x is zero, then n must be positive.
	// Postcondition: The value returned is x raised to the power n.

	void indented_sentences(size_t m, size_t n);
	// Precondition: m <= n
	// Postcondition: The sentences are printed out with m index, increasing by one until n is 
	// indents are placed. Then the scentences are printed out with n index decreasing by one
	// until m is encountered
*/

#ifndef munoz05
#define munoz05

#include <iostream>

namespace M_munoz_05
{
	void binary_print(std::ostream& outs, unsigned int n);
	void triangle(std::ostream& outs, unsigned int m, unsigned int n);
	double power(double x, int n);
	void indented_sentences(size_t m, size_t n);
}

#endif // !munoz05