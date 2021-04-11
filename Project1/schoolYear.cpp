#include "schoolYear.h"
#include <iostream>
using namespace std;

void createNewSchoolYr (schoolYr & a, classR* classLs , ifstream & fin){
    //create new school year with file txt.
    //This file txt format:
    /*
        num_of_class
        semester
        start day
        end day
    */
    fin >> a.num_of_class; 
    a.classLs = classLs;
    fin >> a.semester;
    inputADate(a.start_day, fin);
    inputADate(a.end_day, fin);
}

