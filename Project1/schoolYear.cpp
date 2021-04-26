#include "schoolYear.h"
void createSchoolYr (schoolYr & _init_ )
{
    cout<<"Which year is this school year? \n";
    cin.get();
    getline(cin,_init_.schoolYrNo);
    inputADateFromConsole(_init_.start_day , "Start date");
    inputADateFromConsole(_init_.end_day,  "End day");
    cout<<"How many new classes are there in this school Year \n";
    cin>>_init_.num_of_class;
    ofstream fout;
    fout.open("./schoolYear/schoolYear.txt",ios_base::app);
    if(!fout.is_open())cout<<"can not open file \n";
    else 
    { 
         fout<<_init_.schoolYrNo<<"\n";
         outputADate(_init_.start_day,fout);
         outputADate(_init_.end_day,fout);
         fout<<_init_.num_of_class<<"\n";
    }
    fout.close();

}