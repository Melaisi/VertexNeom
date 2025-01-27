//////////////
/* Lesson 1 */
//////////////

//#include"CommonUtilities.h"
//
//// value 
//// & by reference
//
//
//int main() {
//
//	std::vector<int> numbers = { 1,2,3,4,5 };
//	AddIntToLastIndex(numbers, 10);
//	PrintVectorSize(numbers);
//	return 0;
//}

//////////////
/* Lesson 2 */
//////////////

#include <iostream>
#include <string>

#include "Phone.h"
#include "Book.h"

int main() {

	Phone iPhone("iPhone11", 82737);
	iPhone.ChargeBattery(50);
	iPhone.MakeCall();

	std::cout << "\n=============================\n";

	// Custom class Book
	Book MagicSkyBook("The Magic Skies!");
	MagicSkyBook.AddPage("This an experimental string to see how is the page printing works with long text.");
	MagicSkyBook.AddPage("Second page ! Nothing to see here!");
	// Print Pages in the book to see how it looks
	MagicSkyBook.Read();


	return 0;
}