#include "file.h"
std::ifstream readFile(std::string fileName, int totalLine, int blockLine) {
  std::ifstream is(fileName);
  if (is) {
    for (int i = 0; i < totalLine - blockLine; ++i) {
      std::string tmp;
      getline(is, tmp);
    }
  }
  return is;
}
int countLine(std::string fileName) {
  std::ifstream fin;
  fin.open(fileName);
  int count = 0;
  if (fin.is_open()) {
    while (fin.good()) {
      std::string line;
      std::getline(fin, line);
      ++count;
    }
  }
  return count;
}
bool file_is_empty(std::string fileName) {
  std::ifstream ifs(fileName, std::ios::ate);  // std::ios::ate means open at end

  if (ifs.tellg() == 0) {
    return true;
  }
  ifs.close();
  return false;
}
