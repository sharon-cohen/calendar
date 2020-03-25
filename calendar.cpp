	
#include "calendar.h"
#include "MyDate.h"
#include <string.h>

//sharon coehn 208463463
// dana aloni	207907742
Calendar::Calendar()
{
	for (int i = 0; i < 30; i++)
	{
		ArryDate[i] = nullptr;

	}

}

int Calendar::setDate(const MyDate &newDate, int num)
{
	
	if (num >= 0 && num < 30)
	{
		if (ArryDate[num] == nullptr)
		{
			ArryDate[num] = new MyDate();
		
			if (ArryDate[num] == NULL)
			{
				return 0;
			
			}
			
			
			*ArryDate[num] = newDate;
			return 1;
		}

		else
			return 0;
	}
	else
	{
		return -1;
	}
	
}

bool Calendar::isFree(int num)
{
	if (num >= 0 && num < 30)
	{
		if (ArryDate[num] == nullptr)
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;
}


int Calendar::firstFree()
{
	for (int i = 0; i < 30; i++)
	{
		if (ArryDate[i] == nullptr)
		{
			return i;
		}

	}
	return -1;
}
int Calendar::insert(const MyDate& newDate)
{
	int result=firstFree();
	if (result == -1)
	{
		return -1;
	}
	ArryDate[result] = new MyDate();
	*ArryDate[result]=newDate;
	return 0;
}

int Calendar:: nullend()
{
	int lastfull = 0;
	int checkempty = 0;
	for (int i = 0; i < 30; i++)
	{
		if (ArryDate[i] != nullptr)
		{
			checkempty++;
			lastfull = i;

		}

	}
	if (checkempty == 0)
	{
	
		return 0;
	}

	for (int i = lastfull - 1; i >= 0; i--)
	{

		if (ArryDate[i] == nullptr)
		{
			ArryDate[i] = ArryDate[lastfull];
			ArryDate[lastfull] = nullptr;
			lastfull--;
		}


	}

	return checkempty;

}



int Calendar::oldest()
{
	
	int numfull = -1;
	int min = 0;
	int result = 0;
	
	for (int i = 0; i < 30; i++)
	{
		if (ArryDate[i] != nullptr)
		{
			numfull = i;
			break;
		
		}

	}
	
	
	if (numfull != -1)
	{
		min = numfull;
		for (int i = numfull; i < 29; i++)
		{

			if (ArryDate[i + 1] != nullptr)
			{
				result = ArryDate[min]->isBefore(*ArryDate[i + 1]);

				if (result == 0)

				{
					min = i + 1;

				}
			}


		}

		return min;
	}
	else
	{
		cout << "empty";
		return 0;
	}
}
int Calendar::datesNum(const MyDate& newDate)
{
	int counter = 0;
	
	for (int i = 0; i < 30; i++)
	{
		if (ArryDate[i] != nullptr)
		{
			if (ArryDate[i]->compare(newDate))
			{
				counter++;
			}
		}
	}
	return counter;
}
void Calendar::deleteAll()
{
	for (int i = 0; i < 30; i++)
	{
		if (ArryDate[i] != nullptr)
		{
			ArryDate[i]->initial();
		}

	}

}
int Calendar::deleteDate(int num)
{
	if (num >= 0 && num < 30)
	{
		if (ArryDate[num] == nullptr)
		{
			return -1;
		}
		else
		{
			ArryDate[num]->initial();
			return 0;
		}
	}
	else
		return -1;
}
char* Calendar::print()
{
	
	int emptyarr = 0;
	char *empty = new char[20];
	
	strcpy(empty, "empty calendar");
	
	char *error= new char[10];
	strcpy(error, "error");
	
	char *strDates= new char[360];
	if (strDates == NULL)
	{
		return error;
	}
	char *strtemp=new char[11];
	if (strtemp == NULL)
	{
		return error;
	}
	int FlagIsFirst = 0;
	char space = ' ';
	
	for (int i = 0; i < 30; i++)
	{
		if (ArryDate[i] != nullptr)
		{
			
			emptyarr = 1;
			if (FlagIsFirst == 0)
			{
				
				strtemp = ArryDate[i]->print();
				strcpy(strDates, strtemp);
				FlagIsFirst = 1;
				strncat(strDates, &space, 1);
			}
			else
			{
				
				strtemp = ArryDate[i]->print();
				strcat(strDates, strtemp);
				strncat(strDates, &space, 1);
			}
			
		}
		
	}

	if (emptyarr==0)
	{
		
		
		delete[] strtemp;
		delete[] strDates;
		
		return empty;
		

	}
		
		
	else
	{
		delete[] strtemp;
		return strDates;
	}
	
	
}
void Calendar::sortDates()
{

	MyDate *tmp = new MyDate();
	int checkempty = nullend();
	if (checkempty == 0)
	{
		cout << "empty" << endl;
		return;
	}
	
	for (int n = 0; n < checkempty - 1; n++)
	{
		for (int j = 0; j < checkempty - 1; j++)
		{

			if (ArryDate[j]->isBefore(*ArryDate[j + 1]) == false)
			{
				tmp = ArryDate[j];
				ArryDate[j] = ArryDate[j + 1];
				ArryDate[j + 1] = tmp;
			}


		}
	}
	tmp = nullptr;
	delete tmp;
	

}
 Calendar::~Calendar()
{
	 for (int i = 0; i < 30; i++)
	 {
		 if (ArryDate[i] != nullptr)
		 {
			 delete ArryDate[i];
		 }
	 }

 }