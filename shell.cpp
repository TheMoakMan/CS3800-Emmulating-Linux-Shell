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
    args.pop();
    
    if(args.front() == "-l")
      this->ls_l();
    else  
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
  else if(command == "touch"){
    numArgs--;
    
    for(int i = 0; i < numArgs; i++){
      args.pop();
      this->touch(args.front());
    } 
  }
  else if(command == "cd"){
    args.pop();
    this->cd(args.front());  
  }
  else if(command == "chmod"){
    if(args.size() < 3)
      cout << "chmod: missing operand" << endl;
    else{
      args.pop();

      if(valid_int_str(args.front())){
        int perms = stoi(args.front());
        
        if(perms >= 0 && perms <= 777){
          args.pop();
          this->chmod(perms, args.front());
        }
        else
          cout << "chmod: invalid mode: '" << perms << "'" << endl;
      }
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
  currDir->printPerms();
}

void Shell::cd(string fName)
{
  if(fName == ".."){
    if(currDir->getParent() != nullptr){
      Folder * temp = currDir->getParent();
      currDir = temp;

      string origName = currDir->get_name();
      origName.pop_back();

      currDir->set_name(origName);
    }  
  } 

  if(currDir->contains(fName)){
    if(currDir->getFile(fName)->is_base()){
      cout << "-bash: cd: " << fName << ": Not a directory" << endl;
    } 
    else{  
      Folder * temp = currDir->openFolder(fName);
      
      string altName = currDir->get_name();
      altName.append("/");

      currDir->set_name(altName);

      currDir = temp;  
    } 
  }
  else
    cout << "-bash: cd: " << fName << ": No such file or directory" << endl;
}

void Shell::mkdir(string fName)
{
  currDir->addFile(makeFolder(fName, currDir));
}

void Shell::rmdir(string fName)
{
  if(currDir->contains(fName)){
    if(!(currDir->getFile(fName)->is_base()))
      currDir->rmFile(fName);
    else 
      cout << "rmdir: failed to remove '" << fName << "': Not a directory" << endl;
  } 
  else 
    cout << "rmdir: failed to remove '" << fName << "': No such file or directory" << endl; 
}

void Shell::touch(string fName)
{
  currDir->addFile(makeFile(fName));
}

void Shell::rm(string fName)
{
  if(currDir->contains(fName)){  
    if(currDir->getFile(fName)->is_base())
      currDir->rmFile(fName);
    else
      cout << "rm: cannot remove '" << fName << "': Is a directory" << endl;
  }
  else
    cout << "rm: cannot remove '" << fName << "': No such file or directory" << endl;
}
void Shell::chmod(int perms, string fName)
{
  if(currDir->contains(fName)){
    currDir->getFile(fName)->set_permissions(perms);
  }
  else
    cout << "chmod: cannot access '" << fName << "': No such file or directory" << endl;
}

