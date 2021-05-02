#include "semester.h"
void createASemester(semester& _init_, schoolYr _recentYr_) {
  cout << "Which number is this semester (1 ,2 or 3)\n";
  cin >> _init_.No;
  cin.get();
  _init_._this_year = &_recentYr_;
  cout << "When does this semester start" << endl;
  inputADate(_init_.start_date, cin);
  cout << "When does this semester end " << endl;
  inputADate(_init_.end_date, cin);
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
    fout << endl;  //12 12 2021
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
      fin = readFile(path, totalLine, 5);
      string _tmp;
      getline(fin, _tmp);
      fin >> ws;
      fin >> _load_.No;
      fin.get();
      inputADate(_load_.start_date, fin);
      fin >> ws;
      inputADate(_load_.end_date, fin);
      fin >> ws;
    }
  } else
    return false;
  fin.close();
  return true;
}
