#include "FileManipulate.h"

bool is_empty(std::fstream  pFile)
{
    if( pFile.peek() == pFile.eof())
    return true ;
    else return false;
}