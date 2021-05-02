#ifndef _DATE_H_
#define _DATE_H_
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include "file.h"
using namespace std;

struct Date {
  int date, month, year;
};
void getCurrentDate(Date &Current);
void inputADate(Date &a, istream &fin);
void outputADate(Date a, ostream &fout);
void inputADateFromConsole(Date &a, string dateA = " ");
void outputADateToScreen(Date a);
bool compare2CharArr(char arr1[], char arr2[]);
int exactOrderOfDay(Date &a);
int compare2Days(Date a, Date b);  //1: a is after b , 0: a is b, -1: a is before b;
#endif
