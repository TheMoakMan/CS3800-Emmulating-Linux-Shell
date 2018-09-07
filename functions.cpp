#include "functions.h"

//File interactions
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

Folder * fCast(File * f)
{
  return static_cast<Folder *>(f);
}

//Shell Interactions
void run_shell()
{
  

}

queue<string> get_input()
{
  queue<string> argQueue;
  string arguments;

  getline(cin, arguments, '\n');

  string arg;
  istringstream argStream(arguments);
  while(getline(argStream, arg, ' ')){
    argQueue.push(arg);
  }

   return argQueue;
}
