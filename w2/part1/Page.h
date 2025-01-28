#pragma once

#include <iostream>

// A class that represent a page in a book that allow user to interact with. Each page represent a single face.
class Page
{
public:
	Page(int PageNumber);
	void AddContent(std::string Operation, std::string content); // Add content to the page, Operation can be "Append" or "Replace".
	void ClearContent(); // Empty the content of the current Page
	void PrintPage(); // Print current page
	int getPageNumber();
private:
	int PageNumber;
	std::string Content; // Currently content only text based
	int PageLength; // The Page fixed Length measured in lines
	int PageWidth; // The Page fixed width measured in characters

	// Content Operations
	void AppendToContent(std::string Value);
	void ReplaceContent(std::string Value);

};

