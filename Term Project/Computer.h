/*Written by James Curtis Addy*/
#ifndef  COMPUTER_H
#define COMPUTER_H
#include <string>

using namespace std;

class Computer
{
	public:
		Computer();
		Computer(string newName, string newBrand, string newModel, int newSpeed, string newSerial, int newNumber);
		string GetName() const;
		string GetBrand() const;
		string GetModel() const;
		int GetSpeed() const;
		string GetSerial() const;
		int GetNumber() const;
		void Write() const;
		bool operator<(const Computer& comp);
		bool operator>(const Computer& comp);
		bool operator==(const Computer& comp);
	private:
		string name;
		string brand;
		string model;
		int speed;
		string serialNumber;
		int inventoryNumber;	
};
#endif // ! COMPUTER_H
