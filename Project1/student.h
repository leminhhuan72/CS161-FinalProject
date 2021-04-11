#ifndef _STUDENT_H_ 
#define _STUDENT_H_ 
#include "date.h"
struct accountInfo{
	string name;
	string pass;
};

struct student 
{
	int No;
	string StudentID;
	string First_name;
	string Last_name;
	bool Gender;
	Date Date_of_Birth;
	string SocialID;
	//input a student 	
};
void inputAStudent(student& a , ifstream &fin );
void saveAStudent(student &a , ofstream &fout );
void outputAStudent(student &a , ofstream &fout );
void studentLogin();

#endif 
