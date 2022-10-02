#include "date.h"
#include <iostream>
using namespace std;

void date::SetDay(int a)
{
	day = a;
}

int date::GetDay()
{
	return day;
}

void date::SetMonth(int b)
{
	month = b;
}

int date::GetMonth()
{
	return month;
}

void date::SetYear(int c)
{
	year = c;
}

int date::GetYear()
{
	return year;
}

date::date() {
	day = 0;
	month = 0;
	year = 0;
}

date::date(int a, int b, int c) {
	day = a;
	month = b;
	year = c;
}

void date::Print() {
	cout << "day: " << day << "\nmonth:" << month << "\nyear:" << year << endl;
}

date date::operator++(int)
{
	date temp;
	temp.day = day;
	temp.month = month;
	temp.year = year;
	day++;
	if (day == 28&&month == 2) {
			day = 1;
			month += 1;
	}
	else if (day == 30&& month == 4 or 6 or 9 or 11) {
			day = 1;
			month += 1;
	}
	else if (day == 31&& month == 3 or 1 or 5 or 7 or 8 or 10 or 12) {
			day = 1;
			month += 1;
	}
	
	if (month > 12) {
		day = 1;
		month = 1;
		year += 1;
	}
	return temp;
}

date date::operator--(int)
{
	date temp;
	temp.day = day;
	temp.month = month;
	temp.year = year;
	day --;
	if (day < 1) {
		month -= 1;
		if (month == 1 || 3 || 5 || 7 || 8 || 10 || 12) {
			day = 31;
		}
		else if (month == 4 || 6 || 9 || 11) {
			day = 30;
		}
		else if (month == 2) {
			day = 28;
		}
	}
	if (month < 1) {
		month = 12;
		day = 31;
		year -= 1;
	}
	return temp;
}

date date::operator+(int a)
{
	day + a;
	if (day > 28 && month == 2) {
			day-=28;
			month += 1;
	}
	else if (day == 30 && month == 4 or 6 or 9 or 11) {
			day-= 30;
			month += 1;
	}
	else if (day == 31&&month == 1 || 3 || 5 || 7 || 8 || 10 || 12) {
			day-=31;
			month += 1;
	}

	if (month > 12) {
		month = 1;
		year += 1;
	}
	return *this;
}

date date::operator-(int a)
{
	day - a;
	if (day < 1) {
		month -= 1;
		if (month == 1 || 3 || 5 || 7 || 8 || 10 || 12) {
			day+= 31;
		}
		else if (month == 4 || 6 || 9 || 11) {
			day+= 30;
		}
		else if (month == 2) {
			day+= 28;
		}
	}
	if (month < 1) {
		month = 12;
		day+= 31;
		year -= 1;
	}
	return *this;
}

date date::operator-(const date& obj)
{
	this->day - obj.day;
	if (this->day < 1) {
		month -= 1;
		if (month == 1 || 3 || 5 || 7 || 8 || 10 || 12) {
			this->day += 31;
		}
		else if (month == 4 || 6 || 9 || 11) {
			this->day += 30;
		}
		else if (month == 2) {
			this->day += 28;
		}
	}
	if (month < 1) {
		month = 12;
		this->day += 31;
		year -= 1;
	}
	this->month - obj.month;
	if (month < 1) {
		month+= 12;
		year--;
	}
	this->year - obj.year;
	return date();
}

date date::operator+=(int a)
{
	day += a;
	if (day > 28&& month == 2) {
			day -= 28;
			month += 1;
	}
	else if (day == 30&&month == 4 || 6 || 9 || 11) {
			day -= 30;
			month += 1;
	}
	else if (day == 31&&month == 1 || 3 || 5 || 7 || 8 || 10 || 12) {
			day -= 31;
			month += 1;
	}

	if (month > 12) {
		month = 1;
		year += 1;
	}
	return *this;
}

date date::operator-=(int a)
{
	day -= a;
	if (day < 1) {
		month -= 1;
		if (month == 1 || 3 || 5 || 7 || 8 || 10 || 12) {
			day += 31;
		}
		else if (month == 4 || 6 || 9 || 11) {
			day += 30;
		}
		else if (month == 2) {
			day += 28;
		}
	}
	if (month < 1) {
		month = 12;
		day += 31;
		year -= 1;
	}
	return *this;
}

bool date::operator<(const date& obj)
{
	if (year < obj.year) {
		return true;
	}
	else if (year == obj.year) {
		if (month < obj.year) {
			return true;
		}
	}
	else if (year == obj.year) {
		if (month==obj.year) {
			if (day < obj.day) {
				return true;
			}
		}
	}
	else {
		return false;
	}
}

bool date::operator>(const date& obj)
{
	if (year > obj.year) {
		return true;
	}
	else if (year == obj.year) {
		if (month > obj.year) {
			return true;
		}
	}
	else if (year == obj.year) {
		if (month == obj.year) {
			if (day > obj.day) {
				return true;
			}
		}
	}
	else {
		return false;
	}
}

bool date::operator<=(const date& obj)
{
	if (day == obj.year && month == obj.month && year == obj.year) {
		return true;
	}
	else if (year < obj.year) {
		return true;
	}
	else if (year == obj.year) {
		if (month < obj.year) {
			return true;
		}
	}
	else if (year == obj.year) {
		if (month == obj.year) {
			if (day < obj.day) {
				return true;
			}
		}
	}
	else {
		return false;
	}
}

bool date::operator>=(const date& obj)
{
	if (day == obj.year && month == obj.month && year == obj.year) {
		return true;
	}
	if (year > obj.year) {
		return true;
	}
	else if (year == obj.year) {
		if (month > obj.year) {
			return true;
		}
	}
	else if (year == obj.year) {
		if (month == obj.year) {
			if (day > obj.day) {
				return true;
			}
		}
	}
}

bool date::operator==(const date& obj)
{
	if (day==obj.year&&month==obj.month&&year==obj.year){
		return true;
	}
	else
	return false;
}

bool date::operator!=(const date& obj)
{

	if (day == obj.year && month == obj.month && year == obj.year) {
		return false;
	}
	else
		return true;
}





