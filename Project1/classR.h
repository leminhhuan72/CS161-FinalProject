#ifndef _CLASSR_H_ 
#define _CLASSR_H_ 

#include "student.h"


struct classR {
	//Add new 1st year students to 1st-year classes.
    
	int num_of_students;
	student* member;   // class 20CTT1 ; 20CTT1.member[]
};

void createAClass (classR & _init_, ifstream & fin);
void addStudent2Class (classR & _this_class_ , ifstream & fin );
#endif 

