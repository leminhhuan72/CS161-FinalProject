#ifndef _COURSE_H_
#define _COURSE_H_

#include "classR.h"

using namespace std;

struct session {
  int shift;  //(1,2,3,4)
  string day_in_week;
};
struct inforLecture {
  string username;
  string name;
  string degree;
  string gender;
};

struct course {
  int num;           //so thu tu
  int numOfCredits;  //so tin chi
  int maxStudent;    //so luong hoc sinh toi da
  string ID;         // ma mon hoc vi du CS162
  string fullname;   // ten mon hoc
  string classroom;  //phong hoc
  Date startDate;
  Date finishDate;
  session first;
  session second;
  course* pNext;
  inforLecture lecturer;
};
struct courseRegisSession {
  Date start_date;
  Date end_date;
};
struct schoolYr;
struct semester {
  int No;  //1 : fall , 2:spring , 3 : summer
  schoolYr* _this_year;
  Date start_date;
  Date end_date;
  course* list_of_course;
  Date regis_start;
  Date regis_end;
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
bool storecoursesList(semester& recent);
void createARegisSession(courseRegisSession& recent);
bool loadCourses(semester& recent_sem);
void viewListOfCourse(semester recent_sem);
void outputACourseToScr(course a);
void deleteACourse(course*& totalCourse);
bool check1(string test);
void updateCourseInfo(course*& totalCourse);
void enrollACourse(student& recent, semester& recent_sem);
void scheduleExtract(semester& recent_sem, int& week_1, int& shift_1, int& week_2, int& shift_2, int courseNo);
#endif
