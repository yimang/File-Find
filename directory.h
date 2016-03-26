#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "list.h"

class File
{
protected:
  char *name;
public:
  File(const char *nam);
  const char* getName() const;
  virtual ~File();
  virtual bool find(const File *newFile);
  virtual void insert(File *newFile);
  virtual bool operator==(const File &rhs) const;
  virtual bool operator<(const File &rhs) const;
  virtual bool operator>(const File &rhs) const;
}; // File

class Directory: public File
{
protected:
  List<File> files;
public:
  Directory(const char *nam);
  virtual ~Directory();
  virtual bool find(const File *newFile);
  virtual void insert(File *newFile);
  virtual bool operator==(const File &rhs) const;
  virtual bool operator<(const File &rhs) const;
  virtual bool operator>(const File &rhs) const;
}; // class Directory

#endif // DIRECTORY_H