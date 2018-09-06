#include "folder.h"

File * makeFile(string name, int perms)
{
  File * f1 = new File(name, perms);
  return f1;
}

File * makeFolder(string name, int perms)
{
  Folder * f1 = new Folder(name, perms);
  return f1;
}
