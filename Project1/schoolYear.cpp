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
  ofstream fout;
  fout.open("./schoolYear/schoolYear.txt", ios_base::app);
  if (!fout.is_open())
    cout << "can not open file \n";
  else {
    fout << _init_.schoolYrNo << endl;
    outputADate(_init_.start_day, fout);
    fout << endl;
    outputADate(_init_.end_day, fout);
    fout << endl;
    fout << _init_.num_of_class << endl;
  }
  fout.close();
}
bool loadSchoolYr(schoolYr& _load_) {
  ifstream fin;
  string path = "./schoolYear/schoolYear.txt";
  fin.open(path);
  if (fin.is_open()) {
    if (file_is_empty(path))
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
    }
  } else
    return false;
  fin.close();
  return true;
}