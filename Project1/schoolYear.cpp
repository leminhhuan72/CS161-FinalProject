#include "schoolYear.h"
void createSchoolYr (schoolYr & _init_, ofstream & fout  )
{
    cout<<"Which year is this school year? \n";
    cin.get();
    getline(cin,_init_.schoolYrNo);
    inputADateFromConsole(_init_.start_day , "Start date");
    inputADateFromConsole(_init_.end_day,  "End day");
    cout<<"How many new classes are there in this school Year \n";
    cin>>_init_.num_of_class;

}