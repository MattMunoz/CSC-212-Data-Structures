//#include <iostream>     // Provides cout and cin
//#include <cstdlib>      // Provides EXIT_SUCCESS
//#include <cstring>      // Provides memcpy
//#include "sequence2.h"  // Provides the sequence class with double items.
//using namespace std;
//using namespace main_savitch_4;
//
//void display(const sequence seq, int num);
//
//
//void display(const sequence seq, int  n)
//{
//	cout << "Sequence " << n << ": ";
//	for (int i = 0; i < seq.size(); i++)
//	{
//		cout << seq[i] << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	int s = 10;
//	sequence test1(s);
//	sequence test2(s);
//	sequence test3(s);
//	sequence test4(s);
//	sequence test5(s);
//
//	cout << "Inserting numbers into the sequences...test(1-5)\n";
//	for (int i = 0; i < s; i++)
//	{
//		test1.attach(i);
//		test2.attach(i + 10);
//		test3.attach(i + 20);
//		test4.attach(i + 30);
//		test5.attach(i + 40);
//	}
//
//	cout << "\n--------------Sequences are ase follows--------------" << endl;
//	cout << "Displaying all of the numbers in the sequene using the [] oprator" << endl << endl;
//
//	display(test1, 1);
//	display(test2, 2);
//	display(test3, 3);
//	display(test4, 4);
//	display(test5, 5);
//
//	cout << "\n\n--------------Adding sequences together using the + and += operators--------------\n";
//
//	sequence test6 = test1 + test4;
//
//	cout << "\nSequence 1 + Sequence 4\n";
//	display(test6, 6);
//
//	cout << "\nSequence 3 += Sequence 5\n";
//	test3 += test5;
//	display(test3, 3);
//
//	cout << "\nSequence 6 += Sequence 2\n";
//	test6 += test2;
//	display(test6, 6);
//
//	cout << "\nFinally, Sequence 6 + Sequence 4" << endl;
//	sequence test7 = test6 + test4;
//	display(test7, 7);
//
//	return EXIT_SUCCESS;
//}