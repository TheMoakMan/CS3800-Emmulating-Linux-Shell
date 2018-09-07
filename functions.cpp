#include "functions.h"

//File interactions
File * makeFile(string name)
{
  File * f1 = new File(name);
  return f1;
}

File * makeFolder(string name)
{
  Folder * f1 = new Folder(name);
  return f1;
}

Folder * fCast(File * f)
{
  return static_cast<Folder *>(f);
}

//Shell Interactions
void run_shell()
{
  Shell bash;
  File * home = makeFolder(bash.wd());

  while(bash.is_active()){
    //Wait for user input.
    if(bash.home() != bash.wd())
      cout << "ebmy83@Desktop:" << bash.home() << bash.wd() << "$ ";
    else
      cout << "ebmy83@Desktop:" << bash.home() << "$ ";

    bash.selectCommand(get_input());
  }

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
