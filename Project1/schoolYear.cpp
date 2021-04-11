#include "schoolYear.h"
#include <iostream>
using namespace std;

void createNewSchoolYr (schoolYr & a, classR* classLs){
    //create new school year
   cout << "Class ID: "; cin >> a.num_of_class;
   cout << "Semester: "; cin >> a.semester;
   cout << "Start day: "; inputADate(a.start_day, cin);
   cout << "End day: "; inputADate(a.end_day, cin);
}

