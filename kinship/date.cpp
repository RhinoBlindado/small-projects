#include <iostream>
#include "date.h"

		/*	Implementation*/
/* Constructor without parameters.
 DESCR: Creates an instance without any information set
 PARAM: N/A
 RETUR: N/A
*/
date::date()
{
//	A date with negative values will be understood as "Not Set".
	this->day = -1;
	this->month = -1;
	this->year = -1;
}

		/*	Constructor with Parameters*/
date::date(int date_day, int date_month, int date_year)
{
    this->day  = date_day;
    this->month = date_month;
    this->year = date_year;
}
		/*	Modify the day*/
void date::modDay(int new_day)
{
    this->day = new_day;
}
		/*	Modify the month*/
void date::modMonth(int new_month)
{
    this->month = new_month;
}
		/*	Modify the year*/
void date::modYear(int new_year)
{
    this->year = new_year;
}
		/*	Copy the date from another 'date' object*/
void date::copyDate(date original)
{
	this->day = original.day;
	this->month = original.month;
	this->year = original.year;	
}
		/*	Get the day*/
int date::getDay()
{
    return this->day;
}
		/*	Get the month*/
int date::getMonth()
{
    return this->month;
}
		/*	Get the year*/
int date::getYear()
{
    return this->year;
}

/* Get the complete date
 DESCR: Obtain a string with the date format DD/MM/YYYY.
 PARAM: N/A
 RETUR: String containing "DD/MM/YYYY".
*/
std::string date::getDate()
{
	return std::to_string(this->day) + "/" + std::to_string(this->month) + "/" + std::to_string(this->year);
}

		/*	Print to screen the date*/
void date::printDate()
{
  std::cout<<this->day<<"-"<<this->month<<"-"<<this->year;
}