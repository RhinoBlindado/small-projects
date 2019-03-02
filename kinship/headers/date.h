#ifndef DATE_H_
#define DATE_H_

#include <iostream>

class date
{
    /*Atributes*/
        int day;
        int month;
        int year;

    /*Methods*/
    public:

        /*Constructor*/
        date();
        date(int date_day, int date_month, int date_year);
        
        /*Destructor*/
        ~date(){};

        /*Input*/
        void modDay(int new_day);
        void modMonth(int new_month);
        void modYear(int new_year);
		void copyDate(date original);
		
        /*Output*/
        int getDay();
        int getMonth();
        int getYear();
        std::string getDate();

        /*Debug*/
        void printDate();

};
#endif
