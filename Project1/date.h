#ifndef _DATE_H_ 
#define _DATE_H_ 
#include <iostream>
#include <fstream>
#include <string>

using namespace std ; 


struct Date {
	int date, month, nhat; //, nhat;
};
void inputADate (Date &a , ifstream & fin );
void outputADate(Date a ,ofstream &fout );


#endif 

