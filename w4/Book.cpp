#include "Book.h"

// Initialize a book with title
Book::Book(std::string title)
{
	this->Title = title;
	this->NumberOfPages = 0;
}

// Add New Page with content
void Book::AddPage(std::string PageContent)
{
	// Allocate a new page number
	int NewPageNumber = this->NumberOfPages + 1;
	// Initialize Page
	Page PageToAdd(NewPageNumber);
	// Add Content
	PageToAdd.AddContent("Append", PageContent);

	// Add Page to Book Pages
	this->Pages.push_back(PageToAdd);

	// Update Pages Number
	this->NumberOfPages++;
}

void Book::Read()
{
	if (this->NumberOfPages == 0) {
		std::cout << "No Pages to Read!";
		return;
	}

	std::cout << "\n<x><x><x><x> Reading " << this->Title << " <x><x><x><x>\n";
	
	for (auto& Page : this->Pages) {
		std::cout << "\n\n--------------- Page No." << Page.getPageNumber() << " ---------------\n";
		Page.PrintPage();
		std::cout << "\n\n--------------- End of Page No." << Page.getPageNumber() << " ---------------\n";
		// Ask user for what they want to do next
		std::cout << "\nPlease press N to go to next page or Q to stop reading: ";
		char input;
		std::cin >> input;
		while (input != 'n' && input != 'q') {
			std::cout << "\nPlease press N to go to next page or Q to stop reading: ";
		}
		if (input == 'q') {
			// break the reading loop and exist
			break;
		}
		// Assume user pressed n
	}
}
