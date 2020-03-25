#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "MyDate.h"
#include "calendar.h"
int main()
{
	MyDate d1(29 ,12, 2000);
	MyDate d2(25, 12, 2000);
	MyDate d3(3, 10, 1980);
	MyDate d4(29, 12, 2010);
	MyDate d5(29, 12, 1010);
	MyDate d6(4, 10, 1980);
	//d2.init();

	Calendar c1;
	Calendar c2;
	c1.setDate(d1,2);
	c1.setDate(d2, 4);
	c1.setDate(d3, 6);
	c1.setDate(d4, 12);
	c1.setDate(d5, 20);
	c1.setDate(d6,22);
	//c1.datesNum(d6);
	//c1.sortDates();
	
	cout << c1.oldest();
	c1.~Calendar();
	cin.get();	
}
