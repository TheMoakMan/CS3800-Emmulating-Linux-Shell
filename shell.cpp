#include "functions.h"

void Shell::selectCommand(queue<string> args)
{
  int numArgs = args.size();
  string command = args.front();

  //Check Command and decide on which path to take.
  if(command == "pwd"){
    this->pwd();   
  }
  else if(command == "exit"){
    this->exit();
  }
  else if(command == "mkdir"){
    numArgs--;
    
    for(int i = 0; i < numArgs; i++){
      args.pop();
      this->mkdir(args.front());
    }
  }
  else if(command == "ls"){
    this->ls();
  }
  else if(command == "rm"){
    numArgs--;
    
    for(int i = 0; i < numArgs; i++){
      args.pop();
      this->rm(args.front());
    }
  }
  else if(command == "rmdir"){
    numArgs--;
    
    for(int i = 0; i < numArgs; i++){
      args.pop();
      this->rmdir(args.front());
    } 
  }
  else{
    return; 
  }
  
}

void Shell::pwd()
{
  cout << currDir->get_name() << endl;
}

void Shell::ls()
{
  if(currDir->numFiles() > 0)
    currDir->print();
}

void Shell::ls_l()
{

}

void Shell::cd(string filePath)
{

}

void Shell::mkdir(string fName)
{
  currDir->addFile(makeFolder(fName));
}

void Shell::rmdir(string fName)
{
  if(!(currDir->getFile(fName)->is_base()))
    currDir->rmFile(fName);
  else 
    cout << "rmdir: failed to remove '" << fName << "': Not a directory" << endl;
}

void Shell::touch(string fName)
{

}

void Shell::rm(string fName)
{
  if(currDir->getFile(fName)->is_base())
    currDir->rmFile(fName);
  else
    cout << "rm: cannot remove '" << fName << "': Is a directory" << endl;
}

void Shell::chmod(int perms, string fName)
{

}

