#include "list.h"
#include "directory.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void read(const char *fileName, List<File> &list)
{
  char line[256], *ptr, *temp;
  File *fptr;
  ifstream inf;
  inf.open(fileName, ios::in);
  
  while(inf.getline(line, 256))
  {      
    if(line[0] == 'd')
    {
      ptr = strtok(line, " ");
      
      while((temp = strtok(NULL, " ")))
        ptr = temp;
      fptr = new Directory(ptr);
      list.insert(fptr);
    } // if directory
    else // regular file
    {
      ptr = strtok(line, " ");
      
      while((temp = strtok(NULL, " ")))
        ptr = temp;
      fptr = new File(ptr);
      list.insert(fptr);
    } // if regular file
  }  // while more in file
  
  inf.close();
} // read()

int main(int argc, char *argv[])
{
  char input[256];
  List<File> list;
  File *file;
  
  read(argv[1], list);
  
  cout << "Please enter a file name (Done = exit): ";
  
  while(cin >> input)
  {
    if(!strcmp(input, "Done"))
      return 0;

    file = new File(input);

    if(list.find(file) == false)
      cout << "Not found." << endl;
    cout << "Please enter a file name (Done = exit): ";
  } // get user input loop
  
  return 1;  
} // main()

