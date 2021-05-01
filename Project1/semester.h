#ifndef _SEMESTER_H_
#define _SEMESTER_H_

#include "course.h"

struct schoolYr;
struct semester {
  int No;  //1 : fall , 2:spring , 3 : summer
  schoolYr* _this_year;
  Date start_date;
  Date end_date;
  course* list_of_course;
};

void createASemester(semester& _init_, schoolYr _recentYr_);
#endif