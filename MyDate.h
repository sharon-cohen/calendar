#pragma once
#include <iostream>


using namespace std;

class MyDate
{
private:
	int _day;
	int _month;
	int _year;

public:
	MyDate();
	MyDate(int day, int month, int year);

	void init();
	int set(int day, int month, int year);
	void initial();
	int setDay(int day);
	int setMonth(int month);
	int setYear(int year);
	bool isBefore(const MyDate& newDate);
	int delay(int num);
	int bringForward(int num);
	char* print();
	int compare(const MyDate& checkDate);


	~MyDate() {};
	
};

