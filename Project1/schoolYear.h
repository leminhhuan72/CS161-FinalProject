#ifndef _SCHOOLYEAR_H_
#define _SCHOOLYEAR_H_
#include "classR.h"
#include "date.h"


struct schoolYr {
	int num_of_class; 
	classR* classLs;
	int semester;
	Date start_day;
	Date end_day;
	// schoolYr createASchoolYr() {
	// }
};
void createNewSchoolYr (schoolYr & a, classR* classLs);
#endif 

