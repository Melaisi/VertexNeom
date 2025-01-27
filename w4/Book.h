#pragma once
#include <iostream>
#include <vector>

#include "Page.h"


// A class that represent a book, allowing users to interact with the book.
class Book
{
public:
	Book(std::string title);
	void AddPage(std::string PageContent);
	void Read(); // Iterate over pages to read them expect user to input n to see next page.
private:
	std::string Title; // Book title
	int NumberOfPages =0;
	std::vector<Page> Pages;
};
