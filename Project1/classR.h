#ifndef _CLASSR_H_ 
#define _CLASSR_H_ 
#include "schoolYear.h"
#include "student.h"
#include "date.h"
struct classR
{
	string name;
    schoolYr * schoolYear;
	//Add new 1st year students to 1st-year classes.
	int num_of_students;
	student* member;   // class 20CTT1; 20CTT1.member[]
};

void createAClass(classR & _init_);
void inputAClass (string path , classR& dest,ifstream & fin );
#endif 

