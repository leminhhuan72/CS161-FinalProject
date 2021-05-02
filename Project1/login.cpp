#include "login.h"

void login() {
  for (int i = 0; i < 6; ++i)
    cout << '\t';
  cout << "THIS IS HCMUS PORTAL "
       << "\n";
  for (int i = 0; i < 3; ++i)
    cout << '\t';
  cout << "ARE YOU STUDENT OR STAFF ( Enter 1 if you are student , 2 if you are staff " << endl;
  Date Now;
  getCurrentDate(Now);
  cout << "The current date is ";
  outputADateToScreen(Now);
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
      semester recent_sem;
      if (loadSchoolYr(recent)) {
        cout << "The recent school year is " << recent.schoolYrNo << endl;
        cout << "The start date is ";
        outputADateToScreen(recent.start_day);
        cout << "The end date is ";
        outputADateToScreen(recent.end_day);
        cout << "There are " << recent.num_of_class << " classes in this school year\n\n";
      } else {
        cout << "please input a new schoolYear\n";
        cout << "1: input a new school Year\n";
        cout << "2: exit\n";
        int n;
        while (cin >> n) {
          if (n == 1) {
            createSchoolYr(recent);
            break;
          } else if (n == 2)
            return;
          else
            cout << "1: input a new school Year\n 2: exit \n";
        }
      }
      if (loadSemester(recent_sem, recent)) {
        cout << "The recent semester is ";
        switch (recent_sem.No) {
          case 1:
            cout << "Fall\n";
            break;
          case 2:
            cout << "Spring\n";
            break;
          default:
            cout << "Summer\n";
            break;
        }
        cout << "The start date of this semester is ";
        outputADateToScreen(recent_sem.start_date);
        cout << "The end date of this semester is ";
        outputADateToScreen(recent_sem.end_date);

      } else {
        cout << "please input a new semester\n";
        cout << "1: input a new semester\n";
        cout << "2: exit\n";
        int n;
        while (cin >> n) {
          if (n == 1) {
            createASemester(recent_sem, recent);
            break;
          } else if (n == 2)
            return;
          else
            cout << "1: input a new school Year\n 2: exit \n";
        }
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
          createSchoolYr(recent);
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
        case 4: {
          semester _init_;
          createASemester(_init_, recent);
          if (storecoursesList(_init_.list_of_course, _init_))
            cout << "STORE COURSES INFORMATION SUCCESSFULLY!" << endl;
          else
            cout << "STORE COURSES INFORMATION UNSUCCESSFULLY!" << endl;

          break;
        }
        default:
          cout << "Please input right numbers";
          break;
      }
    } else {
      cout << "GOOD BYE!!!!!";
    }
  }
}