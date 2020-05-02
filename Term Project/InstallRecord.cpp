/*Written by James Curtis Addy*/
#include"InstallRecord.h"
#include <iostream>

InstallRecord::InstallRecord()
{}

InstallRecord::InstallRecord(string newName, string newBrand, string newModel, int newSpeed, string newSerial, int newNumber, string newLocation, SimpleDate newDate) 
	: Computer(newName, newBrand, newModel, newSpeed, newSerial, newNumber)
{
	location = newLocation;
	date = newDate;
}

string InstallRecord::GetLocation() const { return location; }

SimpleDate InstallRecord::GetDate() const { return date; }

void InstallRecord::Write() const
{
	Computer::Write();
	cout << "Location: " << location << endl;
	date.Write();
}

void InstallRecord::ChangeLocation(string newLocation)
{
	this->location = newLocation;
}

bool InstallRecord::operator==(const InstallRecord& install_record)
{
	return this->GetName() == install_record.GetName() && this->GetBrand() == install_record.GetBrand()
		&& this->GetModel() == install_record.GetModel() && this->GetSpeed() == install_record.GetSpeed()
		&& this->GetLocation() == install_record.GetLocation() && this->GetNumber() == install_record.GetNumber()
		&& this->GetSerial() == install_record.GetSerial() && this->GetDate() == install_record.GetDate();
}