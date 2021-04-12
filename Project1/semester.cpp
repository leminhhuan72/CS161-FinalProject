#include "semester.h"
void createASemester (semester& _init_ ,ifstream &fin )
{
   cout<<"Which number is this semester (1 ,2 or 3)";
   cin>> _init_.No;
   cout<<endl ;
   cout<<"What school year is this semester belong to ";
   // choose a particular school year  
   cout<< "When does this semester start"<<endl;
    inputADate (_init_.start_date , cin );
    cout<<"When does this semester end "<<endl; 
    inputADate(_init_.end_date,cin);
    cout<<"Do you want to add course to this semester (Y/N) "<<endl ;
    char hook;
    cin>>hook;
    while(hook=='Y')
    {
      courseRegis(_init_.list_of_course);
      cout<<"Do you want to add course to this semester (Y/N) "<<endl ;
      cin>>hook;
    }
   


}

struct semester { 
    int No ;
    schoolYr year_of_this_semester ; 
    Date start_date ; 
    Date end_date ;
    course * list_of_course ;
};