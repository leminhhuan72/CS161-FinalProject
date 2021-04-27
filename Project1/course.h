#ifndef _COURSE_H_
#define _COURSE_H_

#include "student.h"

using namespace std;


struct times {
	int minu;
	int hour;
};
struct session{
	times time;
	string day;
};
struct inforLecture {
	string username;
	string name;
	string degree;
	string gender;
};

struct course{
	int num; //so thu tu
	string name;// ma mon hoc vi du CS162
	string fullname;// ten mon hoc
	times startTime;
	times finishTime;
	string classroom; //phong hoc
	string clas; // lop hoc vi du 20ctt1, viet class khong duoc nen dung clas :(
	Date startDate;
	Date finishDate;
	session first;
	session second;
	course* pNext;
	inforLecture lecturer;
};
void courseRegis(course*& totalCourse);




#endif 

