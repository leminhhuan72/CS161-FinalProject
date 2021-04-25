#ifndef _DATE_H_ 
#define _DATE_H_ 
#include <iostream>
#include <fstream>
#include <string>

using namespace std ; 


struct Date 
{
	int date, month, year;
};
void inputADate (Date &a , istream & fin );
void outputADate(Date a ,ofstream &fout );
void inputADateFromConsole(Date &a ,string dateA);
void outputADateToScreen (Date a);
#endif 

