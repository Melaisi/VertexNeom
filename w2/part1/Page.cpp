#include "Page.h"

Page::Page(int PageNumber)
{
	// Initialize Page number
	this->PageNumber = PageNumber;

	// TODO: Make sure this logic work
	// Initialize Page width and length
	this->PageLength = 10;
	this->PageWidth = 50;

	// Initialize empty content
	this->Content = "";
}

// Interactive Adding content to existing Page
// TODO: Operations can be enum
void Page::AddContent(std::string Operation, std::string content)
{
	// Operation are either Append or Replace
	if (Operation == "Append") {
		AppendToContent(content);
		return;
	}
	if (Operation == "Replace") {
		ReplaceContent(content);
		return;
	}

	// Otherwise print error
	std::cout << "Cannot perform operation (" << Operation << "), it should be (Append) or (Replace)";

}

// Clear out the current content of the Page
void Page::ClearContent()
{
	this->Content = "";
}

// Print current page content
// TODO: Frame can be its own logic
void Page::PrintPage()
{
	std::cout << this->Content;
	/*
	// TODO: Make sure this logic work
	//// Set top frame
	//char TopFrame = 'o';

	//// prepare side frame
	//std::string SideFrame = "o";

	//// Prepare side padding left and right are the same
	//int SidePadding = 2;

	//// Prepare content to fill page based on length and width including paddings
	//int ContentLineWidth = PageWidth - (SideFrame.length() * 2) - (SidePadding*2);

	//// Divide the content string by the content line to see how many lines we need to print the content
	//// TODO: add an end-line or replace last letter with (-) if we need one.
	//
	//// make sure we have space
	//bool IsContent = true;
	//if (ContentLineWidth == 0 || this->Content.length() == 0) {
	//	// Print empty lines
	//	IsContent = false;
	//}


	//if (IsContent) {
	//	// calculate how many lines we need to print the content ensuring it does not exceed the page length
	//	int ContentLines = this->Content.length() / ContentLineWidth;

	//	if (ContentLines > (this->PageLength - 2)) {
	//		// Can print page
	//		// Start printing
	//		std::cout << std::string(PageWidth, TopFrame)<<std::endl; // print Top Frame

	//		int CharacterIndex = 0;
	//		// Iterate over lines without top and bottom frame
	//		for (int LineIndex = 1; LineIndex <= this->PageLength - 2; LineIndex++) {
	//			// Print Right side frame and padding
	//			std::cout << SideFrame;
	//			std::cout << std::string(SidePadding, ' ');

	//			// Logic to print content the size of Width of ContentLineWidth
	//			// Check if the contentLineWidth doesn't exceed the string length
	//			if (ContentLineWidth - 1 >= Content.length()) {
	//				ContentLineWidth = Content.length() - CharacterIndex - 1;
	//			}
	//			std::cout << Content.substr(CharacterIndex, ContentLineWidth - 1) << std::endl;
	//			// update the character Index
	//			CharacterIndex += ContentLineWidth - 1;

	//			//// Print Right side frame and padding
	//			std::cout << SideFrame;
	//			std::cout << std::string(SidePadding, ' ');
	//			std::cout << std::endl;
	//		}

	//		// Print out bottom Frame with Page Number
	//		std::cout << std::string((PageWidth / 2) - 4, TopFrame); // print Left Side of Bottom Frame
	//		std::cout << " " << PageNumber << " ";
	//		std::cout << std::string((PageWidth/2)-4 , TopFrame) << std::endl; // print Right Side of Bottom Frame
	//		
	//	}
	//	else {
	//		std::cout << "Cannot Print This Page As Page Contents Lines exceeds Page limits!\n";
	//		return;
	//	}
	//}
	//else {
	//	// print empty lines
	//	// Start printing
	//	std::cout << std::string(PageWidth, TopFrame) << std::endl; // print Top Frame
	//	// Iterate over lines without top and bottom frame
	//	for (int LineIndex = 1; LineIndex <= this->PageLength - 2; LineIndex++) {
	//		// Print Left side frame and padding
	//		std::cout << SideFrame;
	//		std::cout << std::string(SidePadding, ' ');
	//		// Print Empty lines
	//		std::cout << std::string(ContentLineWidth, ' ');
	//		// Print Right side frame and padding
	//		std::cout << SideFrame;
	//		std::cout << std::string(SidePadding, ' ');
	//		std::cout << std::endl;
	//	}
	//	// Print out bottom Frame with Page Number
	//	std::cout << std::string((PageWidth / 2) - 4, TopFrame); // print Left Side of Bottom Frame
	//	std::cout << " " << PageNumber << " ";
	//	std::cout << std::string((PageWidth / 2) - 4, TopFrame) << std::endl; // print Right Side of Bottom Frame
	//}
	*/

	return;
}

int Page::getPageNumber()
{
	return this->PageNumber;
}

// Append new content to current page content
void Page::AppendToContent(std::string Value)
{
	this->Content.append(Value);
}

void Page::ReplaceContent(std::string Value)
{
	this->Content = Value;
}
