#include "date.h"
void inputADate (Date &a , istream &fin )
{
    fin>>a.date ; 
    fin>>a.month ;
    fin>>a.year ; 
}
void outputADate (Date a, ofstream& fout)
{
    fout<<a.date<<" "<<a.month<<' '<<a.year<<endl; 
}
void outputADateToScreen (Date a)
{
    cout<<a.date<<" "<<a.month<<' '<<a.year<<endl; 
}
