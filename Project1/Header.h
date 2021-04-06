#ifndef _FUNTIONC_H_ 
#define _FUNTIONC_H_ 
#include <iostream>
#include <fstream>
using namespace std; 
struct Date {
	int date, month, year;

};
struct student {
	int No;
	char* StudentID;
	char* First_name;
	char* Last_name;
	int Gender;
	Date Date_of_Birth;
	char* SocialID;
	//input a student 
	
};
struct classR {
	//Add new 1st year students to 1st-year classes.
    
	int num_of_students;
	student* member;   // class 20CTT1 ; 20CTT1.member[]
};

struct schoolYr {
	int num_of_class; 
	classR* classLs;
	int semester;
	Date start_day;
	Date end_day;
	schoolYr createASchoolYr() {

	}
};
//Add new 1st year students to 1st - year classes.
void inputAStudent(student& a, ifstream& fin);
void inputaDate(a.Date_of_Birth, fin);

#endif 