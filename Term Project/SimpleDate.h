/*Written by James Curtis Addy*/
#ifndef SIMPLEDATE_H
#define SIMPLEDATE_H

class SimpleDate
{
	public:
		SimpleDate();
		SimpleDate(int year, int month, int dayOfMonth);
		SimpleDate(const SimpleDate& date);
		int GetYear() const;
		int GetMonth() const;
		int GetDayOfMonth() const;
		void Write() const;
		bool operator==(const SimpleDate& date);
		bool operator<(const SimpleDate& date);
	private:
		int year;
		int month;
		int dayOfMonth;
};
#endif // !SIMPLEDATE_H
