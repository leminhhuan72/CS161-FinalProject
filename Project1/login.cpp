#include "login.h"

void login() {
  for (int i = 0; i < 6; ++i)
    cout << '\t';
  cout << "THIS IS HCMUS PORTAL "
       << "\n";
  for (int i = 0; i < 3; ++i)
    cout << '\t';
  cout << "ARE YOU STUDENT OR STAFF ( Enter 1 if you are student , 2 if you are staff " << endl;
  int n;
  cin >> n;
  while (n != 1 && n != 2) {
    cout << "Please input 1 if you are student or 2 if you are staff";
    cin >> n;
  }
  cin.get();
  if (n == 1) {
    studentLogin();
  } else if (n == 2) {
    if (staffLogin()) {
      schoolYr recent;
      if (loadSchoolYr(recent)) {
        cout << "The recent school year is " << recent.schoolYrNo << endl;
        cout << "The start date is ";
        outputADateToScreen(recent.start_day);
        cout << "The end date is ";
        outputADateToScreen(recent.end_day);
        cout << "There are " << recent.num_of_class << "classes in this school year\n";
      } else {
        cout << "please input a new schoolYear\n";
      }
      cout << "WHICH TASK YOU WANT TO DO ?\n";
      cout << "TYPE 1 TO CREATE A NEW SCHOOL YEAR \n";
      cout << "2 TO CREATE A CLASS\n";
      cout << "3 TO ADD STUDENTS TO A CLASS\n";
      cout << "4 TO CREATE A NEW SEMESTER \n";
      int n;
      cin >> n;
      cin.get();
      string PATH;
      ofstream fin(PATH + ".txt", ios::app);
      switch (n) {
        case 1:

        {
          schoolYr _init_;
          createSchoolYr(_init_);
          break;
        }
        case 2: {
          classR _init_;
          createAClass(_init_);
          break;
        }
        case 3: {
          inputAClass();
          break;
        }
          /* case 4: {
          createASemester();
          break;
        }*/
        default:
          cout << "Please input right numbers";
          break;
      }
    } else {
      cout << "GOOD BYE!!!!!";
    }
  }
}