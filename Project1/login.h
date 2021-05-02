#ifndef _LOGIN_H_
#define _LOGIN_H_

#include "schoolYear.h"
void login();
void checkSchoolYr(schoolYr& recent);
void checkSemester(semester& recent_sem, schoolYr& recent);
void checkSchoolYr_st(schoolYr& recent);
void checkSemester_st(semester& recent_sem, schoolYr& recent, Date Now, bool& regisActive);
void menyChoice(schoolYr& recent, semester& recent_sem);
#endif