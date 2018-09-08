#include "functions.h"

//File interactions
File * makeFile(string name)
{
  File * f1 = new File(name);
  return f1;
}

File * makeFolder(string name, Folder * parent)
{
  Folder * f1 = new Folder(name, parent);
  return f1;
}

Folder * fCast(File * f)
{
  return static_cast<Folder *>(f);
}

string perms_convert(int perms)
{
  string bcd = to_string(perms);
  string converted;
  
  for(int i = 0; i < 3; i++){
    if(bcd[i] == '0'){
      converted.append("---");
    }
    else if(bcd[i] == '1'){
      converted.append("--x");
    }
    else if(bcd[i] == '2'){
      converted.append("-w-"); 
    }
    else if(bcd[i] == '3'){
      converted.append("-wx");
    }
    else if(bcd[i] == '4'){
      converted.append("r--");
    }
    else if(bcd[i] == '5'){
      converted.append("r-x");
    }
    else if(bcd[i] == '6'){
      converted.append("rw-");
    }
    else if(bcd[i] == '7'){
      converted.append("rwx");
    }  
  }

  return converted;
}

//Shell Environment
void run_shell()
{
  Shell bash;

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

bool valid_int_str(string str)
{
  bool is_valid = true;

  if(str.size() != 3)
    is_valid = false;
  else
    for(int i = 0; i < 3; i++){
      if(!(str[i] >= '0' && str[i] <= '9'))
        is_valid = false; 
    }

  return is_valid;
}

//Extra Functions
int rand_file_size(File * fl)
{

  
}
