#include "semester.h"
void createASemester(semester& _init_, schoolYr _recentYr_) {
  cout << "Which number is this semester (1 ,2 or 3)\n";
  cin >> _init_.No;
  cin.get();
  _init_._this_year = &_recentYr_;
  cout << "When does this semester start" << endl;
  inputADate(_init_.start_date, cin);
  while (compare2Days(_init_.start_date, _recentYr_.start_day) == -1 || compare2Days(_init_.start_date, _recentYr_.end_day) >= 0) {
    inputADateFromConsole(_init_.start_date, " a day which is after the school year start day and before the school year end day ");
  }
  cout << "When does this semester end " << endl;
  inputADate(_init_.end_date, cin);
  while (compare2Days(_init_.end_date, _recentYr_.end_day) == 1 || compare2Days(_init_.end_date, _init_.start_date) <= 0) {
    inputADateFromConsole(_init_.start_date, " a day which is after the semester start day and before the school year end day ");
  }
  cout << "When does the registration session start" << endl;
  inputADate(_init_.regis_start, cin);
  while (compare2Days(_init_.regis_start, _init_.start_date) == -1 || compare2Days(_init_.regis_start, _init_.end_date) >= 0) {
    inputADateFromConsole(_init_.regis_start, " a day which is after the semester start day and before the semester end day ");
  }
  cout << "When does the registration session end" << endl;
  inputADate(_init_.regis_end, cin);
  while (compare2Days(_init_.regis_end, _init_.end_date) == 1 || compare2Days(_init_.regis_end, _init_.regis_start) <= 0) {
    inputADateFromConsole(_init_.start_date, " a day which is before the semester ends and after the session starts ");
  }

  cout << "Do you want to add course to this semester \n 1 to registrate a course\n 2 to exit " << endl;
  int n;
  cin >> n;
  cin.get();
  ofstream fout;
  string path = "./semester/" + _recentYr_.schoolYrNo + ".txt";
  fout.open(path, ios::app);
  if (!fout.is_open()) {
    cout << "Can not open file to store the date of this semester!\n";
  } else {
    fout << _init_._this_year->schoolYrNo << endl;  //2020-2021
    fout << _init_.No << endl;                      //1
    outputADate(_init_.start_date, fout);           //12 10 2020
    fout << endl;
    outputADate(_init_.end_date, fout);
    fout << endl;
    outputADate(_init_.regis_start, fout);
    fout << endl;
    outputADate(_init_.regis_end, fout);
    fout << endl;
  }
  while (n != 1 && n != 2) {
    cout << "Please input 1 to registrate a course \n 2 to exit \n";
    cin >> n;
  }
  while (n == 1) {
    courseRegis(_init_.list_of_course);
    cout << "Please input 1 to registrate a course \n 2 to exit \n";
    cin >> n;
    while (n != 1 && n != 2) {
      cout << "Please input 1 to registrate a course \n 2 to exit \n";
      cin >> n;
    }
  }
}
bool loadSemester(semester& _load_, schoolYr _recentYr_) {
  ifstream fin;
  string path = "./semester/" + _recentYr_.schoolYrNo + ".txt";
  fin.open(path);
  if (fin.is_open()) {
    if (file_is_empty(path))
      return false;
    else {
      _load_._this_year = &_recentYr_;
      int totalLine = countLine(path);
      fin = readFile(path, totalLine, 7);
      string _tmp;
      getline(fin, _tmp);
      fin >> ws;
      fin >> _load_.No;
      fin.get();
      inputADate(_load_.start_date, fin);
      fin >> ws;
      inputADate(_load_.end_date, fin);
      fin >> ws;
      inputADate(_load_.regis_start, fin);
      fin >> ws;
      inputADate(_load_.regis_end, fin);
    }
  } else
    return false;
  fin.close();
  return true;
}
