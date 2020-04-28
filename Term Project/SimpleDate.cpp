/*Written by James Curtis Addy*/
#include "SimpleDate.h"
#include <iostream>

using namespace std;

SimpleDate::SimpleDate(){}

SimpleDate::SimpleDate(int year, int month, int dayOfMonth)
{
	this->year = year;
	this->month = month;
	this->dayOfMonth = dayOfMonth;
}

SimpleDate::SimpleDate(const SimpleDate& date)
{
	year = date.year;
	month = date.month;
	dayOfMonth = date.dayOfMonth;
}

int SimpleDate::GetYear() const { return year; }
int SimpleDate::GetMonth() const { return month; }
int SimpleDate::GetDayOfMonth() const { return dayOfMonth; }

void SimpleDate::Write() const
{
	cout << "Date: " << year << "-" << month << "-" << dayOfMonth << endl;
}

bool SimpleDate::operator==(const SimpleDate& date)
{
	return this->year == date.GetYear() && this->month == date.GetMonth() && this->dayOfMonth == date.GetDayOfMonth();
}

bool SimpleDate::operator<(const SimpleDate& date)
{
	if (this->year < date.GetYear()) return true;
	if (this->year == date.GetYear())
	{
		if (this->month < date.GetMonth()) return true;
		if (this->month == date.GetMonth())
		{
			if (this->dayOfMonth < date.GetDayOfMonth()) return true;
		}
	}
	return false;
}