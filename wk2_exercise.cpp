/*
1. 
	Ask the user to input 5 integers and store them in a vector
	a. Pass the vector into a funciton
	b. Get The highest number in the vector
	c. Print it out to the user

2.
	a. Ask the User for a number input - don't stop filling out your vector until the user presses 0
	b. Create another function
	c. Iterate every 2 items of the Vector and multiply it by 2
	d. print out the numbers

3.
	Do a reverse for loop and print out the results

4.
	a. Ask the user to input Width and a Height , don't stop until they enter 0
	b. Calculate Square Meters
	c. Total square meters of the house
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// 1.a) Pass the vector into a funciton
void PrintHighestNumberInVector(std::vector <int> IntVector) {
	std::vector<int>::iterator HighestNumberIterator = std::max_element(IntVector.begin(), IntVector.end());
	std::cout << "The highest number is: " << *HighestNumberIterator << " at position: "<<
		HighestNumberIterator - IntVector.begin() << std::endl;
}

// 3.d) print out the numbers
void PrintNumbersInVector(std::vector <int> IntVector, bool reverse = false) {
	
	if (reverse) {
		// Reverse the vector
		std::reverse(IntVector.begin(), IntVector.end());
	}
	std::cout << "The vector values are: { ";
	int elementNumber = 1;
	for (int number : IntVector) {
		std::cout << number;
		if (elementNumber != IntVector.size()) {
			// Add the comma for pretty output
			std::cout << " , ";
		}
		elementNumber++;
	}
	std::cout << " }" << std::endl;
	return;
}

// 2.b) Create another function
void MultiplyNumbersInVectorByStep(std::vector <int> IntVector, int Step, int MultiplyFactor) {
	if (Step <= 0) {
		std::cout << "Steps have to be larger than 0."<<std::endl;
		return;
	}
	if (IntVector.size() <= 0) {
		std::cout << "Input vector aize have to be larger than 0." << std::endl;
		return;
	}
	
	// 2.c Iterate every 2 items of the Vector and multiply it by 2
	for (int i = Step-1; i < IntVector.size(); i=i+Step) {
		IntVector.at(i) *= Step;
	}
	// 3.d print out the numbers
	PrintNumbersInVector(IntVector);
	return;
}

int main() {

	// 1) Ask the user to input 5 integers and store them in a vector
	// Get user input 
	{
		std::vector<int> UserInputVector;
		std::cout << "Input 5 integers pressing enter after each number: " << std::endl;
		int InputValue;
		for (int i = 1; i <= 5; i++) {
			std::cout << "[" << i << "] : ";
			std::cin >> InputValue;
			UserInputVector.push_back(InputValue);
		}
		// 1.a)  Pass the vector into a funciton
		PrintHighestNumberInVector(UserInputVector);
	}

	// 2.a) Ask the User for a number input - don't stop filling out your vector until the user presses 0
	{
		std::vector<int> UserInputZeroLimitedVector;
		std::cout << "Input any integer numbers pressing enter after each number, input 0 to exit." << std::endl;
		int InputNumper;
		while (std::cin >> InputNumper) {
			if (InputNumper == 0) {
				break;
			}
			UserInputZeroLimitedVector.push_back(InputNumper);
		}
		// 2.c Iterate every 2 items of the Vector and multiply it by 2
		std::cout << "Multiply every second input with 2 :" << std::endl;
		MultiplyNumbersInVectorByStep(UserInputZeroLimitedVector, 2, 2);

		//3.Do a reverse for loop and print out the results
		std::cout << "The user input in reverse order: " << std::endl;
		PrintNumbersInVector(UserInputZeroLimitedVector,true);

	}

	// a. Ask the user to input Width and a Height , don't stop until they enter 0
	// b. Calculate Square Meters
	// c. Total square meters of the house
	{
		std::vector<float> RoomsArea;

		float InputWidth;
		float InputHeight;
		float RoomArea;
		float HouseArea = 0;

		while (true) {

			int NextRoomIndex = RoomsArea.size();
			std::cout << "Input room [" << NextRoomIndex + 1 << "] Width In Meters: ";
			std::cin >> InputWidth;
			if (InputWidth <= 0) {
				break;
			}
			std::cout << "Input room [" << NextRoomIndex + 1 << "] Height In Meters: ";
			std::cin >> InputHeight;
			if (InputHeight <= 0) {
				break;
			}

			// Calculate Room Area and push to RoomsArea Vector
			RoomArea = InputWidth * InputHeight;
			RoomsArea.push_back(RoomArea);
			// Calculate House
			HouseArea += RoomArea;
		}
		std::cout << "The house total area is: " << HouseArea << std::endl;
	}


	return 0;
}