#include "functions.h"

const string MONTH = " Sept ";


File::File(File &source)
{
  name = source.name;
  permissions = source.permissions;
  logs = source.logs;
}

/*
  Generates log data listed after permissions with the 
  ls -l command. 
*/
string File::generate_logs()
{
  string logs = " 1 evan evan ";
  int tempRand;

  //Add the file size
  tempRand = rand_file_size(this);
  if(tempRand < 1000){
    if(tempRand < 100)
      logs.append("  ");
    else
      logs.append(" ");

    logs.append(to_string(tempRand));
  }
  else
    logs.append(to_string(tempRand));

  //Add date information
  logs.append(MONTH);

  tempRand = rand_range(7,10);

  if(tempRand < 10){
    logs.append(" ");
  }

  logs.append(to_string(tempRand));

  //Add time information
  logs.append(" ");
  tempRand = rand_range(1,23);

  if(tempRand < 10){
    logs.append("0");
  }
  
  logs.append(to_string(tempRand));
  logs.append(":");

  tempRand = rand_range(1,59);
  
   if(tempRand < 10){
    logs.append("0");
  }

  logs.append(to_string(tempRand));

  return logs;
}