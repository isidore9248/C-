#pragma once

class MyInt_Month
{
public:
	static MyInt_Month Jan() { return MyInt_Month(1); }
	static MyInt_Month Feb() { return MyInt_Month(2); }
	static MyInt_Month Mar() { return MyInt_Month(3); }
	static MyInt_Month Apr() { return MyInt_Month(4); }
	static MyInt_Month May() { return MyInt_Month(5); }
	static MyInt_Month Jun() { return MyInt_Month(6); }
	static MyInt_Month Jul() { return MyInt_Month(7); }
	static MyInt_Month Aug() { return MyInt_Month(8); }
	static MyInt_Month Sep() { return MyInt_Month(9); }
	static MyInt_Month Oct() { return MyInt_Month(10); }
	static MyInt_Month Nov() { return MyInt_Month(11); }
	static MyInt_Month Dec() { return MyInt_Month(12); }
private:
	explicit MyInt_Month(int month) : m_month(month) {}
	int m_month;
};

class MyInt_Day
{
public:
	explicit MyInt_Day(int day) : m_day(day) {}
private:
	int m_day;
};

class MyInt_Year
{
public:
	explicit MyInt_Year(int year) : m_year(year) {}
private:
	int m_year;
};

class MyInt_Date
{
public:
	MyInt_Date(const MyInt_Month& m, const MyInt_Day& d, const MyInt_Year& y) {}
};

void MyInt_test(void);