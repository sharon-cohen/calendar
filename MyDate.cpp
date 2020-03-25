#define _CRT_SECURE_NO_WARNINGS
#include "MyDate.h"
#include <string.h>
MyDate::MyDate()
{
	_day = 0;
	_month = 0;
	_year = 0;


}

MyDate::MyDate(int day, int month, int year)
{
	if (month >= 1 && month <= 12 && year > 1900 && year < 2100)
	{
		if (month == 2 && day <= 28 && day >= 1)
		{
			_day = day;
			_month = month;
			_year = year;

			return;
		}
		else
		{
			if (day <= 30 && day >= 1)
			{
				_day = day;
				_month = month;
				_year = year;

				return;
			}

		}

	}
	_day = 0;
	_month = 0;
	_year = 0;

	
	return;

}

void MyDate::init()
{
	_day = 20;
	_month = 11;
	_year = 2019;

}

void MyDate::initial()
{
	_day = 0;
	_month = 0;
	_year = 0;
	return ;

}

int MyDate::set(int day, int month, int year)
{
	if (month >= 1 && month <= 12 && year > 1900 && year < 2100)
	{
		if (month == 2 && day <= 28 && day >= 1)
		{
			_day = day;
			_month = month;
			_year = year;
			return 0;
		}
		else
		{
			if (day <= 30 && day >= 1)
			{
				_day = day;
				_month = month;
				_year = year;
				return 0;
			}

		}

	}

	return -1;
}
int MyDate::setDay(int day)
{
	if (day <= 30 && day >= 1)
	{
		if (_month == 2)
		{
			if (day <= 28 && day >= 1)
			{
				_day = day;
				return 0;

			}
		}
		else
		{
			_day = day;
			return 0;
		}
	}
	return -1;

}
int MyDate::setMonth(int month)
{
	if (month <= 12 && month >= 1)
	{
		if (month == 2)
		{
			if (_day <= 28 && _day >= 1)
			{
				_month = month;
				return 0;

			}
		}
		else
		{
			_month = month;
			return 0;
		}
	}
	return -1;

}
int MyDate::setYear(int year)
{
	if (year < 2100 && year>1900)
	{
		_year = year;
		return 0;

	}

	return -1;

}

bool MyDate::isBefore(const MyDate& newDate)
{
	if (this->_year < newDate._year)
	{
		return true;

	}
		if (this->_year == newDate._year)
		{
			if (this->_month < newDate._month)
			{
			return true;
			}
			if (this->_month == newDate._month)
			{
				if (this->_day < newDate._day)
				{
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
}

int MyDate::delay(int num)
{
	int startday = _day;
	int startmonth = _month;
	int checkfebru = _month;
	int movemonth = 0;
	bool isfebru = 0;
	int TempDay = 0;
	int TempMonth = 0;
	if (num <= 365)
	{
		TempDay = (num % 30);
		TempMonth =  (num / 30);
		if (_day+TempDay > 30)
		{
			TempMonth++;
			_day = (TempDay+_day) - 30;
		}
		
		else
		{
			_day = _day + TempDay;
		}
		
			for (int i = TempMonth; i > 0; i--)
			{
				
				if (checkfebru > 12)
				{
					checkfebru = checkfebru - 12;
				}
				if (checkfebru == 2)
				{
					isfebru = 1;
				}
			
				checkfebru++;

			}
		
			
			
			if (TempMonth + _month > 12)
			{
				_year++;
				if (_year > 2100)
				{
					_year--;
					_month = startmonth;
					_day = startday;
					return -1;
				}
				
				
				_month = _month + TempMonth - 12;
			}
				else
				{
				_month = _month+TempMonth;
				
				}

			if (isfebru == 1)
			{
				if (_day >= 29)
				{
					if (_month == 12)
					{
						_year++;
						_month = 1;
						_day = (_day - 28);
					}
					else
					{
						_month++;
						_day = (_day - 28);
					}
				}
				else
				{
					_day = _day + 2;
				}
			}

		return 0;
	}

	else
		return -1;


}


char* MyDate::print()
{
	char ch = '/';
	char strday[4];
	_itoa(_day, strday,10);
	strncat(strday, &ch, 1);
	char strmonth[4];
	_itoa(_month, strmonth, 10);
	strncat(strmonth, &ch, 1);
	char stryear[5];
	_itoa(_year, stryear, 10);
	char *result = new char[11];
	
	strcpy(result, strday);
	strcat(result, strmonth);
	strcat(result, stryear);
	
	return result;
	delete[] result;
	

}
int MyDate::bringForward(int num)
{
	int startday = _day;
	int startmonth = _month;
	int checkfebru = _month;
	int movemonth = 0;
	bool isfebru = 0;
	int TempDay = 0;
	int TempMonth = 0;
	if (num <= 365)
	{
		TempDay = (num % 30);
		TempMonth =  (num / 30);
		if ((_day-TempDay) <= 0)
		{
			TempMonth++;
			_day = (30-TempDay)+_day;
		}
		else
		{
			_day = _day-TempDay;
		}
		for (int i = TempMonth; i > 0; i--)
		{
			checkfebru--;
			if (checkfebru == 0)
			{
				checkfebru = 12;
			}
			if (checkfebru == 2)
			{
				isfebru = 1;
			}
		}

		if (_month-TempMonth <= 0)
		{
				_year--;
				if (_year < 1900)
				{
					_year++;
					_month = startmonth;
					_day = startday;
					return-1;
				}
				_month = 12-TempMonth + _month;

		}
		else
		{
			_month = _month-TempMonth;
		}

		if (isfebru == 1)
		{
			if (_day >= 29)
			{
				if (_month == 12)
				{
					_year++;
					_month = 1;
					_day = (_day - 28);
				}
				else
				{
					_month++;
					_day = (_day - 28);
				}
			}
			else
			{
				_day = _day + 2;
			}
		}
		
		return 0;
	}

	else
	return -1;


}
int MyDate::compare(const MyDate& checkDate)
{
	if (_day == checkDate._day)
	{
		if (_month == checkDate._month)
		{
			if (_year == checkDate._year)
			{
				return 1;
			}
			else
				return 0;
		}
		else
			return 0;
	}
	else
		return 0;
}