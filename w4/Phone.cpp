#include "Phone.h"


Phone::Phone(std::string Name, int SerialNumber) : Name(Name), SerialNumber(SerialNumber), BatteryLife(15), InternalTemperature(30.0) {}

void Phone::PrintInformation() {
	std::cout << "This is a:" << Name << std::endl;
	std::cout << "Serial Number is:" << SerialNumber << std::endl;
	std::cout << "Internal Temperature is:" << InternalTemperature << std::endl;
}

void Phone::PrintName() {
	std::cout << Name << std::endl;
}

void Phone::PrintBatteryLife() {
	std::cout << "Current Battery Life: "<< BatteryLife << std::endl;
}

void Phone::TakePicture() {
	std::cout << "Click\n";
}

void Phone::SetFactoryDefaults(float DefaultBatteryLife, float DefaultTemperature) {
	BatteryLife = DefaultBatteryLife;
	InternalTemperature = DefaultTemperature;
}

// Increase the BatteryLife by charge value
void Phone::ChargeBattery(int charge)
{
	// Ensure the charge is positive value
	if (charge < 0) {
		charge = 0;
	}

	// Ensure the value doesn't exceeds 100%
	if (charge + BatteryLife > 100) {
		// check the difference of charge to tell how much we are adding
		charge = 100 - BatteryLife;
	}
	
	// Adding the update charge to battery life
	this->BatteryLife += charge;
	std::cout << "Charging the Battery with "<<charge<<" value.\n";
	
	// Print Updated BatteryLife
	PrintBatteryLife();
	
	return;
}

void Phone::MakeCall()
{
	// check if we can make a call, batteryLife need to be more than 5%
	if (BatteryLife <= 5) {
		std::cout << "Low Battery, Please Charge!\n";
		return;
	}

	// Tell use we made the call and reduce battery!
	std::cout << "Call has been made!\n";
	
	// We only make calls when Battery have more than 5% so if we subtract 5 it should be >=0
	BatteryLife -= 5;
	return;
}

void Phone::setSerialNumber(int SerialNumber)
{
	this->SerialNumber = SerialNumber;
}

int Phone::getSerialNumber()
{
	return this->SerialNumber;
}

