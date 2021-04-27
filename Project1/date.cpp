#include "date.h"
void inputADate (Date &a , istream &fin )
{
    fin>>a.date ; 
    fin>>a.month ;
    fin>>a.year ; 
}
void inputADateFromConsole(Date &a ,string dateA)
{
    cout<<"Please input " <<dateA <<"(ddMMyyyy)\n" ; 
    cin>>a.date>>a.month>>a.year;
    

}
void outputADate (Date a, ostream& fout)
{
    fout<<a.date<<" "<<a.month<<' '<<a.year<<endl; 
}
void outputADateToScreen (Date a)
{
    cout<<a.date<<" "<<a.month<<' '<<a.year<<endl; 
}
