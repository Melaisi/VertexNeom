#pragma once

#include<iostream>

class Phone {

public:
	Phone(std::string Name, int SerialNumber);

	void PrintInformation();
	void PrintName();
	void PrintBatteryLife();
	void TakePicture();
	void SetFactoryDefaults(float DefaultBatteryLife, float DefaultTemperature);
	void ChargeBattery(int charge); // Increase Battery life by the given amount (without going beyond 100%)

	void MakeCall(); // Simulation that reduce BatteryLife by 5% and warn the user when under 5%

	void setSerialNumber(int SerialNumber);
	int getSerialNumber();

private:
	std::string Name;
	int SerialNumber;
	float BatteryLife;
	float InternalTemperature;
};