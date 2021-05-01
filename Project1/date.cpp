#ifdef _CRT_SECURE_NO_WARNINGS
#undef _CRT_SECURE_NO_WARNINGS
#endif
#define _CRT_SECURE_NO_WARNINGS 1 =
#include "date.h"
void inputADate(Date &a, istream &fin) {
  fin >> a.date;
  fin >> a.month;
  fin >> a.year;
}
void inputADateFromConsole(Date &a, string dateA) {
  if (dateA != " ") {
    cout << "Please input " << dateA << "(ddMMyyyy)\n";
  }
  cin >> a.date >> a.month >> a.year;
}
void outputADate(Date a, ostream &fout) {
  fout << a.date << " " << a.month << ' ' << a.year;
}
void outputADateToScreen(Date a) {
  cout << a.date << " " << a.month << ' ' << a.year << endl;
}
bool compare2CharArr(char arr1[], char arr2[]) {
  if (strlen(arr1) != strlen(arr2))
    return false;
  else {
    for (int i = 0; i < strlen(arr1); ++i) {
      if (arr1[i] != arr2[i]) return false;
    }
    return true;
  }
}

void getCurrentDate(Date &Current) {
  char month_sub[12][20] = {
      {"Jan'\0"},
      {"Feb'\0"},
      {"Mar'\0"},
      {"Apr\0"},
      {"May\0"},
      {"Jun\0"},
      {"Jul\0"},
      {"Aug\0"},
      {"Sep\0"},
      {"Oct\0"},
      {"Nov\0"},
      {"Dec\0"}};
  char month[10];
  Current.date = 0;
  time_t now = time(0);
  char *date_time = ctime(&now);

  {
    int i = 9;
    while (date_time[i] != ' ') {
      Current.date = Current.date * 10 + (int)date_time[i] - 48;
      ++i;
    }
  }

  for (int i = 4; i < 7; ++i) {
    month[i - 4] = date_time[i];
  }
  month[3] = '\0';

  Current.month = 0;
  for (int i = 0; i < 12; ++i) {
    if (compare2CharArr(month, month_sub[i])) {
      Current.month = i + 1;
      break;
    }
  }

  Current.year = 0;
  {
    int i = strlen(date_time) - 1;

    while (date_time[i] != ' ') {
      --i;
    }

    for (int j = i + 1; j < strlen(date_time) - 1; ++j) {
      Current.year = Current.year * 10 + (int)date_time[j] - 48;
    }
  }
}
