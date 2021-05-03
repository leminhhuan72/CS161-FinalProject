#ifndef _SCHOOLYEAR_H_
#define _SCHOOLYEAR_H

#include "semester.h"

void createSchoolYr(schoolYr& _init_);
bool loadSchoolYr(schoolYr& _load_);
bool loadClass(schoolYr& recent);
bool canLoadClass(schoolYr& recent);
#endif