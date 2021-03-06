/*Written by James Curtis Addy*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <limits>
#include "InstallRecord.h"
#include "SimpleDate.h"
#include "SortedList.h"

using namespace std;

SortedList<InstallRecord> install_record_list(500);
string original_file_name = "original.dat";
string update_file_name = "update.dat";

void HandleOperations();
void AddEntry();
void DeleteEntry();
void ChangeLocation();
void PrintSortedEntries();
void PrintByLocation();
void PrintByBrand();
void PrintBeforeDate();
void ReadEntriesFromFile();
void SaveEntriesToFile();
void ClearInput();

int main()
{
	ReadEntriesFromFile();
	HandleOperations();
	return 0;
}

void ReadEntriesFromFile()
{
	ifstream input_file;
	//First, see if the update.dat file already exists
	string file_name = update_file_name;
	input_file.open(file_name);
	if (!input_file)
	{		
		//If update.dat isn't available, try original.dat
		file_name = original_file_name;
		input_file.open(file_name);
		if (!input_file)
		{
			cout << "There is currently no " << original_file_name << " or " << update_file_name << " file to read from." << endl;
			return;
		}
	}
	string current_line;
	while (getline(input_file, current_line))
	{
		stringstream string_stream(current_line);
		string name, brand, model, serial, location;	
		int speed, inventory_number,  installation_year, installation_month, installation_day_of_month;	
		string_stream >> name >> brand >> model >> speed >> serial >> inventory_number >> location >> installation_year >> installation_month >> installation_day_of_month;
		SimpleDate install_date(installation_year, installation_month, installation_day_of_month);	
		InstallRecord record(name, brand, model, speed, serial, inventory_number, location, install_date);
		install_record_list.Insert(record);
	}
	input_file.close();
	cout << "Loaded entries from " << file_name << endl;
}

void SaveEntriesToFile()
{
	ofstream save_file(update_file_name);
	for (int i = 0; i < install_record_list.GetLength(); i++)
	{
		InstallRecord record = install_record_list[i];
		SimpleDate record_date = record.GetDate();
		save_file << record.GetName() << " " 
			<< record.GetBrand() << " "
			<< record.GetModel() << " "
			<< record.GetSpeed() << " "
			<< record.GetSerial() << " "
			<< record.GetNumber() << " "
			<< record.GetLocation() << " "
			<< record_date.GetYear() << " "
			<< record_date.GetMonth() << " "
			<< record_date.GetDayOfMonth() << endl;
	}
	save_file.close();
	cout << "Install records have been saved to " << update_file_name << "." << endl;
}

void HandleOperations()
{
	char user_operation = ' ';
	char exit_character = 'i';
	while (user_operation != exit_character)
	{		
		cout << "\nList of record operations:\n"
			<< "a. Add a new computer to the list.\n"
			<< "b. Delete a computer from the list.\n"
			<< "c. Change the location of a computer.\n"
			<< "d. Print a list of all computers in inventory-number order.\n"
			<< "e. Print a list of all computers in a given location.\n"
			<< "f. Print a list of all computer of a particular brand.\n"
			<< "g. Print a list of all computer installed before a given date.\n"
			<< "h. Save entries\n"
			<< exit_character << ". Exit\n\n"
			<< "Enter the character (lowercase) of the desired operation: ";
		cin >> user_operation;
		ClearInput();
		cout << endl;
		if (user_operation == 'a')
		{
			AddEntry();
		}
		else if (user_operation == 'b')
		{
			DeleteEntry();
		}
		else if (user_operation == 'c')
		{
			ChangeLocation();
		}
		else if (user_operation == 'd')
		{
			PrintSortedEntries();
		}
		else if (user_operation == 'e')
		{
			PrintByLocation();
		}
		else if (user_operation == 'f')
		{
			PrintByBrand();
		}
		else if (user_operation == 'g')
		{
			PrintBeforeDate();
		}
		else if (user_operation == 'h')
		{
			SaveEntriesToFile();
		}
		else if (user_operation == exit_character) continue;
		cout << "\nEnter " << exit_character <<" to exit. Enter anything else to continue:";
		user_operation = cin.get();
		cout << endl;
	}	
}

void AddEntry()
{
	cout << "Enter the new computer's info:" << endl;
	string name, brand, model, serial, location;	
	int speed, inventory_number,  installation_year, installation_month, installation_day_of_month;	
	cout << "Name: ";
	cin >> name;
	ClearInput();
	cout << "Brand: ";
	cin >> brand;
	ClearInput();
	cout << "Model: ";
	cin >> model;
	ClearInput();
	cout << "Speed(in MHz): ";
	cin >> speed;
	ClearInput();
	cout << "Serial: ";
	cin >> serial;	
	ClearInput();
	cout << "Inventory Number: ";
	cin >> inventory_number;	
	ClearInput();
	cout << "Location: ";
	cin >> location;
	ClearInput();
	cout << "Installation Date (year month day): ";	
	cin >> installation_year >> installation_month >> installation_day_of_month;
	SimpleDate install_date(installation_year, installation_month, installation_day_of_month);	
	InstallRecord record(name, brand, model, speed, serial, inventory_number, location, install_date);
	install_record_list.Insert(record);
}

void DeleteEntry()
{	
	if (install_record_list.GetLength() <= 0)
	{
		cout << "There are no install entries." << endl;
		return;
	}

	PrintSortedEntries();
	int index;
	cout << "Enter the index value of the entry to delete (-1 to cancel):";
	cin >> index;
	ClearInput();
	if (index == -1) return;	
	if (index >= install_record_list.GetLength())
	{
		cout << "Index out of range." << endl;
		return;
	}
	cout << "Are you sure you want to delete this entry? " << endl;
	install_record_list[index].Write();
	cout << "Enter y for yes:";
	char answer;
	cin >> answer;
	ClearInput();
	if (answer != 'y' && answer != 'Y')
	{
		cout << "Entry deletion cancelled." << endl;
		return;
	}
	install_record_list.Delete(index);
	cout << "Install entry deleted." << endl;
}

void ChangeLocation()
{
	if (install_record_list.GetLength() <= 0)
	{
		cout << "There are no install entries." << endl;
		return;
	}

	PrintSortedEntries();
	int index;
	cout << "Enter the index value of the entry to change location (-1 to cancel):";
	cin >> index;
	ClearInput();
	if (index == -1) return;
	if (index >= install_record_list.GetLength())
	{
		cout << "Index is out of range." << endl;
		return;
	}
	InstallRecord* record = &install_record_list[index]; 
	cout << "The current location of " << record->GetName() << " is " << record->GetLocation()
		<< "\nEnter the new location (-1 to cancel):";
	string new_location;
	cin >> new_location;
	ClearInput();
	if (new_location == "-l") return;
	record->ChangeLocation(new_location);
	cout << install_record_list[index].GetName() << "'s new location set to " << install_record_list[index].GetLocation() << endl;
}

void PrintSortedEntries()
{
	if (install_record_list.GetLength() <= 0)
	{
		cout << "There are no install entries." << endl;
		return;
	}

	cout << "List of Install Records: " << endl;
	for (int i = 0; i < install_record_list.GetLength(); i++)
	{
		cout << "-----------" << endl;
		cout << "Index Value: " << i << endl;
		cout << "-----------" << endl;
		install_record_list[i].Write();
		cout << endl;
	}
}

void PrintByLocation()
{
	if (install_record_list.GetLength() <= 0)
	{
		cout << "There are no install entries." << endl;
		return;
	}

	string location;
	cout << "Enter location to print all installs in that location: ";
	cin >> location;
	ClearInput();
	bool location_found = false;
	for (int i = 0; i < install_record_list.GetLength(); i++)
	{
		InstallRecord record = install_record_list[i];
		if (record.GetLocation() == location)
		{
			record.Write();
			cout << endl;
			if (!location_found) location_found = true;
		}
	}
	if (!location_found)
	{
		cout << location << " is not a location of any of the installs." << endl;
	}
}

void PrintByBrand()
{
	if (install_record_list.GetLength() <= 0)
	{
		cout << "There are no install entries." << endl;
		return;
	}

	string brand;
	cout << "Enter a brand to print all installs of that brand: ";
	cin >> brand;
	ClearInput();
	bool brand_found = false;
	for (int i = 0; i < install_record_list.GetLength(); i++)
	{
		InstallRecord record = install_record_list[i];
		if (record.GetBrand() == brand)
		{
			record.Write();
			cout << endl;
			if (!brand_found) brand_found = true;
		}
	}
	if (!brand_found)
	{
		cout << brand << " is not a brand of any of the installs." << endl;
	}
}

void PrintBeforeDate()
{
	if (install_record_list.GetLength() <= 0)
	{
		cout << "There are no install entries." << endl;
		return;
	}

	cout << "Enter a date (YYYY MM DD) to print installs before that date: ";
	int year, month, day;
	cin >> year >> month >> day;
	ClearInput();
	SimpleDate date(year, month, day);
	bool entries_found = false;
	for (int i = 0; i < install_record_list.GetLength(); i++)
	{
		InstallRecord record = install_record_list[i];
		if (record.GetDate() < date)
		{
			record.Write();
			cout << endl;
			if (!entries_found) entries_found = true;
		}
	}
	if (!entries_found)
	{
		cout << "No installs found before the date " << year << "-" << month << "-" << day << endl;
	}
}

void ClearInput()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}



