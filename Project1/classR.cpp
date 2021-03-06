#include "classR.h"
#include <iostream>
using namespace std;

void createAClass(classR& _init_) {
  cout << "Type the name of the class\n";
  getline(cin, _init_.name);
  cout << "How many students are there in this class\n?";
  cin >> _init_.num_of_students;
  string path = "./class/" + _init_.name + ".txt";
  ofstream fout(path, ios::app);
  if (fout.is_open()) {
    fout << _init_.name << '\n';
    fout << _init_.num_of_students << '\n';
  }
  fout.close();
}

void inputAClass() {  //file csv
  classR dest;
  cout << "What is the name of class ? \n";
  string name;

  getline(cin, name);
  dest.name = name;
  string path_dest = "./class/" + name + ".txt";
  ofstream f(path_dest, ios::app);
  ifstream f_2(path_dest);
  f_2 >> ws;
  if (f_2.eof()) {
    cout << "This is the new class, please input the number of students'\n";

    cin >> dest.num_of_students;
    cin.get();

    f << dest.name << '\n';
    f << dest.num_of_students << '\n';

  } else {
    getline(f_2, dest.name);
    f_2 >> dest.num_of_students;
  }
  //  check whether there has been a file that created or not
  bool check = true;
  bool import_success = false;
  while (check) {
    cout << "What is the path of the file containing information of all students ? ";
    string path_src;
    getline(cin, path_src);
    ifstream fin;
    fin.open(path_src);

    if (fin.is_open() && !file_is_empty(path_src)) {
      check = false;
      import_success = true;
      dest.member = new student[dest.num_of_students];
      for (int i = 0; i < dest.num_of_students; ++i) {
        if (fin.eof()) {
          cout << "there is not enough information about all students of the class\n";
          break;
        }
        fin >> dest.member[i].No;
        fin.get();
        getline(fin, dest.member[i].StudentID, ',');
        getline(fin, dest.member[i].First_name, ',');
        getline(fin, dest.member[i].Last_name, ',');
        fin >> dest.member[i].Gender;
        fin.get();
        fin >> dest.member[i].Date_of_Birth.date;
        fin.get();
        fin >> dest.member[i].Date_of_Birth.month;
        fin.get();
        fin >> dest.member[i].Date_of_Birth.year;
        fin.get();
        getline(fin, dest.member[i].SocialID, ',');
        getline(fin, dest.member[i].userName);
        // 1,20125033,Le,Minh Huan ,1,24,05,2002,22150261,lmhuan2020
      }
    } else {
      cout << "cant not open file \n";
      cout << "do you want to input again or not (Y/n)\n";
      string hook;
      getline(cin, hook);
      if (hook == "n" || hook == "N" || hook == "No" || hook == "no" || hook == "NO")
        check = false;
    }
    fin.close();
  }
  if (import_success)  //if the file is successfully imported
  {
    cout << "IMPORT FILE SUCCESSFULLY!\n";
    for (int i = 0; i < dest.num_of_students; ++i) {
      f << dest.member[i].No << '\n';
      f << dest.member[i].StudentID << '\n';
      f << dest.member[i].First_name << '\n';
      f << dest.member[i].Last_name << '\n';
      f << dest.member[i].Gender << '\n';
      outputADate(dest.member[i].Date_of_Birth, f);
      f << endl;
      f << dest.member[i].SocialID << '\n';
      f << dest.member[i].userName << '\n';
    }
  }

  f.close();
  f_2.close();
}
void viewAClass(classR load) {
  cout << setw(5) << left << "No";
  cout << setw(12) << "ST.ID";
  cout << setw(30) << "FULL NAME";
  cout << setw(6) << "SEX";
  cout << setw(13) << "DOB";
  cout << setw(12) << "SOCIAL.ID" << '\n';
  int size = load.num_of_students;
  string sex[2] = {"Female", "Male"};
  for (int i = 0; i < size; ++i) {
    cout << setw(5) << left << load.member[i].No;
    cout << setw(12) << load.member[i].StudentID;
    cout << setw(30) << load.member[i].First_name + " " + load.member[i].Last_name;
    cout << setw(6) << sex[load.member[i].Gender];
    cout << setw(3) << load.member[i].Date_of_Birth.date;
    cout << setw(3) << load.member[i].Date_of_Birth.month;
    cout << setw(7) << load.member[i].Date_of_Birth.year;
    cout << setw(12) << load.member[i].SocialID << endl;
  }
}
