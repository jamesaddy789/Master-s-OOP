/*Written by James Curtis Addy*/
#ifndef INSTALLRECORD_H
#define INSTALLRECORD_H
#include "Computer.h"
#include "SimpleDate.h"

class InstallRecord : public Computer
{
	public:
		InstallRecord();
		InstallRecord(string newName, string newBrand, string newModel, int newSpeed, string newSerial, int newNumber, string newLocation, SimpleDate newDate);
		string GetLocation() const;
		SimpleDate GetDate() const;
		void ChangeLocation(string newLocation);
		void Write() const;
		bool operator==(const InstallRecord& install_record);
	private:
		string location;
		SimpleDate date;
};
#endif // !INSTALLRECORD_H