#ifndef _FILE_H_
#define _FILE_H_
#include <fstream>
#include <iostream>
#include <string>
std::ifstream readFile(std::string fileName, int totalLine, int blockline);
int countLine(std::string fileName);
#endif