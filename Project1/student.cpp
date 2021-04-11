#include "student.h"
void inputAStudent(student& a , ifstream &fin ){
    fin>>a.No ; 
    getline(fin, a.StudentID);
    getline(fin, a.First_name);
    getline(fin, a.Last_name);
    string gender ; 
    getline(fin, gender );
    if(gender == "male")a.Gender=true ;
    else a.Gender = false ;  
    inputADate(a.Date_of_Birth,fin);
    getline(fin, a.SocialID);

}
void outputAStudent(student &a , ofstream &fout ){
    fout << a.No <<'\n'<<a.StudentID<<'\n'<<a.First_name<<' '<<a.Last_name<<'\n'<<a.Gender<<'\n';
    outputADate(a.Date_of_Birth,fout);
    fout<<a.SocialID<<'\n';
    
}
