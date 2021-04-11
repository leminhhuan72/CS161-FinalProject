#include "student.h"
void inputAStudent(student& a, ifstream& fin)
{
    fin >> a.No;
    getline(fin, a.StudentID);
    getline(fin, a.First_name);
    getline(fin, a.Last_name);
    string gender;
    getline(fin, gender);
    if (gender == "Male")
        a.Gender = true;
    else a.Gender = false;
    inputADate(a.Date_of_Birth, fin);
    getline(fin, a.SocialID);
}
void saveAStudent(student& a, ofstream& fout)
{
    fout << "No:" << '\t' << a.No << endl;
    fout << "Student ID:" << '\t' << a.StudentID << endl;
    fout << "First Name:" << '\t' << a.First_name << endl;
    fout << "Last Name:" << '\t' << a.Last_name << endl;
    fout << "Gender:" << '\t' << a.Gender << endl;
    fout << "Date of birth:" << '\t';
    outputADate(a.Date_of_Birth, fout);
    fout << "Social ID:" << '\t' << a.SocialID << endl;
}