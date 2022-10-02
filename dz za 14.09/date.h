#pragma once
class date
{
	int	day;
	int month;
	int year;
public:
	date();
	date(int a, int b, int c);
	void SetDay(int a);
	int GetDay();
	void SetMonth(int b);
	int GetMonth();
	void SetYear(int c);
	int GetYear();
	/*Point*/
	void Print();
	date operator++(int);
	date operator--(int);
	date operator+(int a);
	date operator-(int a);
	date operator-(const date& obj);
	date operator+=(int a);
	date operator-=(int a);
	bool operator <(const date& obj);
	bool operator >(const date& obj);
	bool operator <=(const date& obj);
	bool operator >=(const date& obj);
	bool operator ==(const date& obj);
	bool operator !=(const date& obj);
};

