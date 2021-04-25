#ifndef _SCHOOLYEAR_H_ 
#define _SCHOOLYEAR_H 
#include "classR.h"
#include "date.h"
#include "semester.h"

struct schoolYr{
   string schoolYrNo ; 
   int num_of_class;
   classR*  classLs;
   semester*  semester_of_this_year;
	Date  start_day;
	Date end_day;
};

void createSchoolYr (schoolYr & _init_, ofstream & fout);
#endif