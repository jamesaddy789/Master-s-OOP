/*Written by James Curtis Addy*/
#include "Computer.h"
#include <iostream>

Computer::Computer()
{}

Computer::Computer(string newName, string newBrand, string newModel, int newSpeed, string newSerial, int newNumber)
{
	name = newName;	
	brand = newBrand;
	model = newModel;
	speed = newSpeed;
	serialNumber = newSerial;
	inventoryNumber = newNumber;
}
string Computer::GetName() const{ return name; }
string Computer::GetBrand() const{ return brand; }
string Computer::GetModel() const { return model; }
int Computer::GetSpeed() const { return speed; }
string Computer::GetSerial() const { return serialNumber; }
int Computer::GetNumber() const { return inventoryNumber; }
void Computer::Write() const
{
	cout << "Name: " << name << endl;
	cout << "Brand: " << brand << endl;
	cout << "Model: " << model << endl;
	cout << "Speed: " << speed << endl;
	cout << "Serial Number: " << serialNumber << endl;
	cout << "Inventory Number: " << inventoryNumber << endl;
}
bool Computer::operator<(const Computer& comp)
{
	return this->GetNumber() < comp.GetNumber();
}
bool Computer::operator>(const Computer& comp)
{
	return this->GetNumber() > comp.GetNumber();
}
bool Computer::operator==(const Computer& comp)
{
	return this->GetNumber() == comp.GetNumber();
}