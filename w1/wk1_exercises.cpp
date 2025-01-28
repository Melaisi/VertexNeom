/*

Week 1: Exercise 1
------------------
1. Ask for the name and age of a user -- print to console.
2. Ask the user for a 
	a. Temperature in Celcius -- Convert to Fh -- print to console
	b. Distance in Km -- convert to Miles -- print to console
	c. Weight in Pounds -- convert to Kgs -- print to console
	d. Money in US Dollar -- convert to Euros -- print to console

3. Create a vector of 4 float numbers
	a. Compute the average of the 4 numbers and print it.
	---- How to compute an average
	---- Find std implemntation for it
4. Ask the user to input 5 integers and store them in a vector
	a. Print the sum of all the integers (std::acc***)
	b. Largest and Smallest number in the vector (*std::...)
	c. Ask the user for a number - search it to see if its in the vector using std
*/

#include <iostream>
#include <vector>
#include <numeric> // To calculate the avrage of a vector
#include <algorithm>

int main() {

	// Answer for 1 
	// Ask for the name and age of a user -- print to console.
	{
		std::cout << "Hello! Please write your First Name: ";
		std::string FirstName;
		std::cin >> FirstName;

		std::cout << "Please write your Last Name: ";
		std::string LastName;
		std::cin >> LastName;

		std::cout << "Welcome " << FirstName << " " << LastName << " !" << std::endl;

		std::cout << "Please input your age: ";
		int UserAge;
		std::cin >> UserAge;

		std::cout << "Your age is : " << UserAge << std::endl;
	}

	// Answer for 2.a
	// a. Temperature in Celcius -- Convert to Fh -- print to console
	{
		std::cout << "Lets convert a few things!" << std::endl;

		std::cout << "Enter Temperature in Celsius: ";
		float TemperatureInCelsius;
		std::cin >> TemperatureInCelsius;
		// Celsius to Fahrenheit conversion formula is : F = (9/5) * C + 32
		float TemperatureInFahrenheit = (TemperatureInCelsius * (9. / 5)) + 32;
		std::cout << "The Temperature in Fahrenheit is: " << TemperatureInFahrenheit << std::endl;
	}

	// Answer for 2.b
	// b. Distance in Km -- convert to Miles -- print to console
	{
		std::cout << "Enter Length in Kilometer: ";
		float LengthInKilometer;
		std::cin >> LengthInKilometer;
		// Kilometer to Miles conversion formula is : Miles = km/1.609344
		float LengthInMile = LengthInKilometer / 1.609344;
		std::cout << "The Length in Miles is: " << LengthInMile << std::endl;
	}

	// Answer for 2.c
	// c. Weight in Pounds -- convert to Kgs -- print to console
	{
		std::cout << "Enter Mass in Pound: ";
		float MassInPound;
		std::cin >> MassInPound;
		// Pound to Kilogram conversion formula is : Pound = kg/2.205
		float MassInKilogram = MassInPound / 2.205;
		std::cout << "The Mass in Kilogram is: " << MassInKilogram << std::endl;
	}

	// Answer for 2.d
	// d. Money in US Dollar -- convert to Euros -- print to console
	{
		std::cout << "Enter Money in US Dollars: ";
		float MoneyInUSD;
		std::cin >> MoneyInUSD;
		// USD to Euro conversion formula is : Euro = USD * ConversionRate
		float USDtoEuroConversionRate = 0.95; // Date: 15 DEC 2024
		float MoneyInEuro = MoneyInUSD * USDtoEuroConversionRate;

		std::cout << "The Money in Euro is: " << MoneyInEuro<< std::endl;
	}

	// Answer for 3
	// Create a vector of 4 float numbers
	//	a.Compute the average of the 4 numbers and print it.
	{
		std::vector<int> VectorNumbers = { 10,10,10,10 };
		double VectorSum = std::accumulate(VectorNumbers.begin(), VectorNumbers.end(), 0.0);

		if (VectorNumbers.size() != 0) {
			double VectorAverage = VectorSum / VectorNumbers.size(); // Avoid division by zero.
			std::cout << "Calculating the average numbers of a vector of " << VectorNumbers.size() << " : { ";
			int elementNumber = 1;
			for (int number : VectorNumbers) {
				std::cout << number;
				if (elementNumber != VectorNumbers.size()) {
					// Add the comma for pretty output
					std::cout << " , ";
				}
				elementNumber++;
			}
			std::cout << " }" << std::endl;
			std::cout << "The average is : " << VectorAverage << std::endl;
		}
		else {
			std::cout << "The Vector is empty, cannot calculate average value." << std::endl;
		}
	}

	// Answer for 4
	// Ask the user to input 5 integers and store them in a vector
	
	{
		std::vector<int> UserInputVector;
		std::cout << "Input 5 integers pressing enter after each number: " << std::endl;
		int InputValue;
		for (int i = 1; i <= 5; i++) {
			std::cout << "[" << i << "] : ";
			std::cin >> InputValue;
			UserInputVector.push_back(InputValue);
		}

		// Answer for 4.a
		// a.Print the sum of all the integers(std::acc***)
		std::cout << "The Sum of the values entered is: " << std::accumulate(UserInputVector.begin(), UserInputVector.end(), 0) << std::endl;
		// Answer for 4.b
		// b.Largest and Smallest number in the vector(*std::...)
		std::cout << "The largest number is: " << *std::max_element(UserInputVector.begin(), UserInputVector.end()) << std::endl;
		std::cout << "The smallest number is: " << *std::min_element(UserInputVector.begin(), UserInputVector.end()) << std::endl;
		
		// c.Ask the user for a number - search it to see if its in the vector using std
		std::cout << "Enter a number to find if it exist among the entered numbers: ";
		int NumberToSearchFor;
		std::cin >> NumberToSearchFor;
		
		auto FindIterator = std::find(UserInputVector.begin(), UserInputVector.end(), NumberToSearchFor);
		if (FindIterator != UserInputVector.end()) {
			// Item has been found
			// Calculate the index of the iterator
			int index = std::distance(UserInputVector.begin(), FindIterator);
			std::cout << "Found the value " << NumberToSearchFor << " at Index " << index << std::endl;
			std::cout << "The value of Index " << index << " is: " << UserInputVector.at(index); // Just to confirm logic
		}
		else {
			std::cout << "The value doesn't exist among the entered numbers." << std::endl;
		}
	}






	return 0;
}