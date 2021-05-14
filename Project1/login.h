#ifndef _LOGIN_H_
#define _LOGIN_H_

#include "schoolYear.h"
void login();
void checkSchoolYr(schoolYr& recent);
void checkSemester(semester& recent_sem, schoolYr& recent);
void checkSchoolYr_st(schoolYr& recent);
void checkSemester_st(semester& recent_sem, schoolYr& recent, Date Now, bool& regisActive);
void menuChoice(schoolYr& recent, semester& recent_sem, bool loadCourse, bool fullClass, bool scoreBoard);
void menuChoice_st(schoolYr& recent, semester& recent_sem, student& recent_stu, bool regisActive, bool scoreBoard, bool fullClass);
#endif