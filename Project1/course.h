#ifndef _COURSE_H_
#define _COURSE_H_

#include "classR.h"

using namespace std;
struct times {
  int minu;
  int hour;
};
struct session {
  times time;
  Date day;
};
struct inforLecture {
  string username;
  string name;
  string degree;
  string gender;
};

struct course {
  int num;          //so thu tu
  string name;      // ma mon hoc vi du CS162
  string fullname;  // ten mon hoc
  times startTime;
  times finishTime;
  string classroom;  //phong hoc
  string clas;       // lop hoc vi du 20ctt1, viet class khong duoc nen dung clas :(
  Date startDate;
  Date finishDate;
  session first;
  session second;
  course* pNext;
  inforLecture lecturer;
};
struct schoolYr;
struct semester {
  int No;  //1 : fall , 2:spring , 3 : summer
  schoolYr* _this_year;
  Date start_date;
  Date end_date;
  course* list_of_course;
};
struct schoolYr {
  string schoolYrNo;
  int num_of_class;
  classR* classLs;
  semester* semester_of_this_year;
  Date start_day;
  Date end_day;
};
void courseRegis(course*& totalCourse);
void storecoursesList(course* totalCourse, semester recent);

#endif
