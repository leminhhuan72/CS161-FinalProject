#ifndef _FUNTIONC_H_ 
#define _FUNTIONC_H_ 
#include <iostream>
using namespace std; 
struct Date {
	int date, month, year;

};
struct student {
	int No;
	char* StudentID;
	char* First name;
	char* Last name :
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
void inputAStudent(student& a, ifstream& fin)
{
	fin >> No;
	a.StudentID = new char[100];
	fin.ignore(100'\n');
	fin.get(a.StudentID, 100, '\n');
	a.First_name = new char[100];
	fin.ignore(100'\n');
	fin.get(a.First_name, 100, '\n');
	a.Last_name = new char[100];
	fin.ignore(100'\n');
	fin.get(a.Last_name, 100, '\n');
	int Gender;
	fin >> Gender;
	Date Date_of_Birth;
	inputaDate(a.Date_of_Birth, fin);
	a.SocialID = new char[100];
		fin.ignore(100'\n');
	fin.get(a.SocialId, 100, '\n');

}


#endif 