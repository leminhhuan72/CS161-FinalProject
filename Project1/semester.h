#ifndef _SEMESTER_H_ 
#define _SEMESTER_H_ 
#include "schoolYear.h"
#include "course.h"


struct semester { 
    int No ;
    schoolYr year_of_this_semester ; 
    Date start_date ; 
    Date end_date ;
    course * list_of_course ;
};

void createASemester (semester& _init_ ,ifstream &fin );


#endif 