#ifndef _COURSE_H_
#define _COURSE_H_
#include <iostream>
#include <fstream>
#include<string.h>
#define nullptr NULL
using namespace std;
struct date {
	int d;
	int m;
	int y;
};
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
	date startDate;
	date finishDate;
	session first;
	session second;
	course* pNext;
	inforLecture lecturer;
};



#endif 

