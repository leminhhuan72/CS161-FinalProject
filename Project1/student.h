#ifndef _STUDENT_H_ 
#define _STUDENT_H_ 
#include "date.h"
<<<<<<< HEAD
=======


>>>>>>> 031adafa7adee606b3a9ff9e086f298923633043
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
bool changePass(string currentPass, string newPass);
void listOfStudentsInCourse(student*& pStudent, string nameyear, string namesemester, string namecourse, int& n);
#endif 
