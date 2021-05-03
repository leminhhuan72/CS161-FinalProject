#include "schoolYear.h"

void createSchoolYr(schoolYr& _init_) {
  cout << "Which year is this school year? \n";
  cin >> ws;
  getline(cin, _init_.schoolYrNo);
  inputADateFromConsole(_init_.start_day, "Start date");
  inputADateFromConsole(_init_.end_day, "End day, which is after Start date ");
  while (compare2Days(_init_.end_day, _init_.start_day) == -1 || compare2Days(_init_.end_day, _init_.start_day) == 0) {
    inputADateFromConsole(_init_.end_day, "End day, which is after Start date ");
  }
  cout << "How many new classes are there in this school Year \n";
  cin >> ws;
  cin >> _init_.num_of_class;
  _init_.classLs = new classR[_init_.num_of_class];
  ofstream fout, fout_2;
  fout.open("./schoolYear/schoolYear.txt", ios_base::app);
  fout_2.open("./class/" + _init_.schoolYrNo + ".txt");
  if (!fout.is_open())
    cout << "can not open file \n";
  else {
    fout << _init_.schoolYrNo << endl;
    outputADate(_init_.start_day, fout);
    fout << endl;
    outputADate(_init_.end_day, fout);
    fout << endl;
    fout << _init_.num_of_class << endl;
    for (int i = 0; i < _init_.num_of_class; ++i) {
      cout << "Input name of the number " << i + 1 << " class" << endl;
      if (i == 0) cin >> ws;
      getline(cin, _init_.classLs[i].name);
      fout_2 << _init_.classLs[i].name << endl;
    }
  }
  fout.close();
}
bool loadSchoolYr(schoolYr& _load_) {
  ifstream fin;
  string path_1 = "./schoolYear/schoolYear.txt";
  fin.open(path_1);
  if (fin.is_open()) {
    if (file_is_empty(path_1))
      return false;
    else {
      int totalLine = countLine("./schoolYear/schoolYear.txt");
      fin = readFile("./schoolYear/schoolYear.txt", totalLine, 5);
      getline(fin, _load_.schoolYrNo);
      inputADate(_load_.start_day, fin);
      fin.get();
      inputADate(_load_.end_day, fin);
      fin.get();
      fin >> _load_.num_of_class;
      fin >> ws;
      _load_.classLs = new classR[_load_.num_of_class];
      string path_2 = "./class/" + _load_.schoolYrNo + ".txt";
      ifstream fin_2;
      fin_2.open(path_2);
      for (int i = 0; i < _load_.num_of_class; ++i) {
        getline(fin_2, _load_.classLs[i].name);
      }
    }
  } else
    return false;
  fin.close();
  return true;
}
bool loadClass(schoolYr& recent) {
  for (int i = 0; i < recent.num_of_class; ++i) {
    ifstream fin;
    string path = "./class/" + recent.classLs[i].name + ".txt";
    cout << path << endl;
    fin.open(path);
    if (fin.is_open() && !file_is_empty(path)) {
      string tmp;
      getline(fin, tmp);
      fin >> ws;
      fin >> recent.classLs[i].num_of_students;
      recent.classLs[i].member = new student[recent.classLs[i].num_of_students];
      int j = 0;
      for (; j < recent.classLs[i].num_of_students; ++j) {
        if (fin.eof()) break;
        inputAStudent(recent.classLs[i].member[j], fin);
      }
      if (j < recent.classLs[i].num_of_students) {
        cout << " 1  Load students of class " << recent.classLs[i].name << " data unsuccessfully!\n";
        return false;
      }
      cout << "Load students of class " << recent.classLs[i].name << " data successfully!\n";
    } else {
      cout << " 2  Load students of class " << recent.classLs[i].name << " data unsuccessfully!\n";
      return false;
    }
  }

  return true;
}
bool canLoadClass(schoolYr& recent) {
  int size = recent.num_of_class;
  for (int i = 0; i < size; ++i) {
    ifstream fin;
    fin.open("./class/" + recent.classLs[i].name + ".txt", ios::ate);
    if (!fin.is_open()) return false;
    if (fin.tellg() > 3)
      return true;
  }
  return false;
}