#pragma once
#include "MyDate.h"


class Calendar
{
private:
	MyDate *ArryDate[30];

public:
	Calendar() ;
	int setDate(const MyDate& newDate, int num);
	bool isFree(int num);
	int firstFree();
	int insert(const MyDate& newDate);
	int oldest();
	int datesNum(const MyDate& newDate);
	void deleteAll();
	int deleteDate(int num);
	char* print();
	int nullend();
	void sortDates();

	~Calendar() ;
	

};
