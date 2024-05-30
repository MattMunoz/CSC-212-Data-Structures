//// file: sequence_test.cxx
//// an interactive test program for the new sequence class
//#include <cctype>       // provides toupper
//#include <iostream>     // provides cout and cin
//#include <cstdlib>      // provides exit_success
//#include "sequence1.h"  // with value_type defined as double
//using namespace std;
//using namespace main_savitch_3;
//
//// prototypes for functions used by this test program:
//void print_menu( );
//// postcondition: a menu of choices for this program has been written to cout.
//
//char get_user_command( );
//// postcondition: the user has been prompted to enter a one character command.
//// the next character has been read (skipping blanks and newline characters), 
//// and this character has been returned.
//
//void show_sequence(sequence display);
//// postcondition: the items on display have been printed to cout (one per line).
//
//double get_number( );
//// postcondition: the user has been prompted to enter a real number. the
//// number has been read, echoed to the screen, and returned by the function.
//
//
//int main( )
//{
//    sequence test; // a sequence that we’ll perform tests on
//    char choice;   // a command character entered by the user
//    
//    cout << "i have initialized an empty sequence of real numbers." << endl;
//
//    do
//    {
//        print_menu( );
//        choice = tolower(get_user_command( ));
//        switch (choice)
//        {
//            case '!': test.start( );
//                      break;
//            case '+': test.advance( );
//                      break;
//            case '?': if (test.is_item( ))
//                          cout << "there is an item." << endl;
//                      else 
//                          cout << "there is no current item." << endl;
//                      break;
//            case 'c': if (test.is_item( ))
//                           cout << "current item is: " << test.current( ) << endl;
//                      else
//                          cout << "there is no current item." << endl;
//                      break;
//            case 'p': show_sequence(test);
//                      break;
//            case 's': cout << "size is " << test.size( ) << '.' << endl;
//                      break;
//            case 'i': test.insert(get_number( ));
//                      break;
//            case 'a': test.attach(get_number( ));
//                      break;
//            case 'r': test.remove_current( );
//                      cout << "the current item has been removed." << endl;
//                      break;     
//            case 'q': cout << "ridicule is the best test of truth." << endl;
//                      break;
//            default:  cout << choice << " is invalid." << endl;
//        }
//    }
//    while ((choice != 'q'));
//
//    return EXIT_SUCCESS;
//}
//
//void print_menu( )
//// library facilities used: iostream.h
//{
//    cout << endl; // print blank line before the menu
//    cout << "the following choices are available: " << endl;
//    cout << " !   activate the start( ) function" << endl;
//    cout << " +   activate the advance( ) function" << endl;
//    cout << " ?   print the result from the is_item( ) function" << endl;
//    cout << " c   print the result from the current( ) function" << endl;
//    cout << " p   print a copy of the entire sequence" << endl;
//    cout << " s   print the result from the size( ) function" << endl;
//    cout << " i   insert a new number with the insert(...) function" << endl;
//    cout << " a   attach a new number with the attach(...) function" << endl;
//    cout << " r   activate the remove_current( ) function" << endl;
//    cout << " q   quit this test program" << endl;
//}
//
//char get_user_command( )
//// library facilities used: iostream
//{
//    char command;
//
//    cout << "enter choice: ";
//    cin >> command; // input of characters skips blanks and newline character
//
//    return command;
//}
//
//void show_sequence(sequence display)
//// library facilities used: iostream
//{
//    for (display.start( ); display.is_item( ); display.advance( ))
//        cout << display.current( ) << endl;
//}
//
//double get_number( )
//// library facilities used: iostream
//{
//    double result;
//    
//    cout << "please enter a real number for the sequence: ";
//    cin  >> result;
//    cout << result << " has been read." << endl;
//    return result;
//}
