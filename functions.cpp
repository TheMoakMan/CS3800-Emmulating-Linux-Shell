#include "functions.h"

/*~~~File interactions~~~*/
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

/*~~~Shell Environment~~~*/
void run_shell()
{
  Shell bash;

  while(bash.is_active()){
    //Wait for user input.
    cout << "ebmy83@Desktop:" << bash.getFilepath(bash.wd()) << "$ ";

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
    if(arg != "")
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

/*~~~Extra Functions~~~*/
int rand_file_size(File * fl)
{
  random_device randDev;
  mt19937 generator(randDev()); 
  
  if(fl->is_base()){
    uniform_int_distribution<int> range(50, 1100);
    return range(generator);
  }
  else{
    uniform_int_distribution<int> range(1000,4500);
    return range(generator);
  }
}

int rand_range(int low, int up)
{
  random_device randDev;
  mt19937 generator(randDev()); 
  
  uniform_int_distribution<int> range(low, up);
  
  return range(generator);
}

void removeQuotes(string & str)
{
  size_t found = str.find('"');
  int pos_1, pos_2;

  if(found != string::npos){
    cout << "Found a quote! " << endl;
    pos_1 = found;
  }

  found = str.find('"', found + 1);
  if(found != string::npos){
    cout << "Found second quote" << endl;
    pos_2 = found;
  }
  
  if(pos_1 != 0){
    int i = pos_1;
    int count = 0;
    while(str[i] != ' ' && i < pos_2){
      count++;
      i++;
    }

    str.replace(pos_1+count, pos_1+count+1, "_");
    str.erase(pos_1);
  }
}