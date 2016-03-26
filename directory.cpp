#include "directory.h"
#include <iostream>
#include <cstring>

File::File(const char *nam)
{  
  name = new char[strlen(nam) + 1];
  strcpy(name, nam);
} // File constructor
 
const char* File::getName() const
{
  return name;
} // getName()
  
File::~File()
{
} // File destructor
  
bool File::find(const File *newFile) 
{
  cout << name << endl;
  return true;
} // find()
  
void File::insert(File *newFile)
{ 
} // insert()
  
bool File::operator==(const File &rhs) const
{
  if(strcmp(name, rhs.getName()) == 0)
    return 1;
  else // false
    return 0;
} // overloaded ==
  
bool File::operator<(const File &rhs) const
{
  if(strcmp(name, rhs.getName()) < 0)
    return 1;
  else // false
    return 0;
} // overloaded <
  
bool File::operator>(const File &rhs) const
{
  if(strcmp(name, rhs.getName()) > 0)
    return 1;
  else // false
    return 0;
} // overloaded >

Directory::Directory(const char *nam): File(nam)
{
} // Directory constructor

Directory::~Directory()
{
} // Directory destructor
  
bool Directory::find(const File *newFile)
{
  if(!strcmp(name, newFile->getName()))
  {
    files.print();
    return true;
  } // perfect match
  else return files.find(newFile); //not perfect match
} // find()

void Directory::insert(File *newFile)
{
  if(!strcmp(name, newFile->getName()));
  else files.insert(newFile); //not perfect match
} // insert()
  
bool Directory::operator==(const File &rhs) const
{
  char *ptr = new char[strlen(name) + 2];
  strcpy(ptr, name);
  *(ptr + strlen(name)) = '/';
  *(ptr + strlen(name) + 1) = '\0';
  
  if(!strncmp(rhs.getName(), ptr, strlen(ptr)) 
     || !strcmp(name, rhs.getName()))
    return 1;
  else // false
    return 0;
} // overloaded ==

bool Directory::operator<(const File &rhs) const
{
  char *ptr = new char[strlen(name) + 2];
  strcpy(ptr, name);
  *(ptr + strlen(name)) = '/';
  *(ptr + strlen(name) + 1) = '\0';
  
  if(strncmp(ptr, rhs.getName(), strlen(ptr)) < 0)
    return 1;
  else // false
    return 0;
} // overloaded <
  
bool Directory::operator>(const File &rhs) const
{
  char *ptr = new char[strlen(name) + 2];
  strcpy(ptr, name);
  *(ptr + strlen(name)) = '/';
  *(ptr + strlen(name) + 1) = '\0';
  
  if(strncmp(ptr, rhs.getName(), strlen(ptr)) > 0)
    return 1;
  else // false
    return 0;
}// overloaded >