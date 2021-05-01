#include "semester.h"
void createASemester(semester& _init_, schoolYr _recentYr_) {
  cout << "Which number is this semester (1 ,2 or 3)\n";
  cin >> _init_.No;
  cin.get();
  cout << "What school year is this semester belong to\n ";
  string schoolYr;
  getline(cin, schoolYr);
  // check whether there has been thís  school YEar
  cout << "When does this semester start" << endl;
  inputADate(_init_.start_date, cin);
  cout << "When does this semester end " << endl;
  inputADate(_init_.end_date, cin);
  cout << "Do you want to add course to this semester (Y/N) " << endl;
  int n;
  cin >> n;
  cin.get();
  cout << " 1 to registrate a  course \n 2 to exit\n ";
  while (n != 1 && n != 2) {
    cout << "Please input 1 to registrate a course \n 2 to exit \n";
    cin >> n;
    cin.get();
  }
  while (n == 1) {
    courseRegis(_init_.list_of_course);
    cout << "Please input 1 to registrate a course \n 2 to exit \n";
    cin >> n;
  }
}
