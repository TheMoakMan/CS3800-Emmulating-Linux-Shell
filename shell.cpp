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
  else{
    return; 
  }
  
}

void Shell::pwd()
{
  cout << this->currDir->get_name() << endl;
}

void Shell::ls()
{

}

void Shell::ls_l()
{

}

void Shell::cd(string filePath)
{

}

void Shell::mkdir(string fName)
{
  cout << "Making Dir: " << fName << endl;
}

void Shell::rmdir(string fName)
{

}

void Shell::touch(string fName)
{

}

void Shell::rm(string fName)
{

}

void Shell::chmod(int perms, string fName)
{

}

