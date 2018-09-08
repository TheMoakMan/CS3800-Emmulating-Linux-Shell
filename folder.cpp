#include "functions.h"

Folder::Folder(Folder &source)
{
  name = source.name;
  permissions = source.permissions;
  parentDir = source.parentDir;
  contents = source.contents;

  is_base_file = false;
}

Folder::~Folder()
{
  for(auto it = contents.begin(); it != contents.end(); it++)
  {
    delete it->second;
  }
}

void Folder::addFile(File * source)
{
  contents[source->get_name()] = source;
}

void Folder::rmFile(string fName)
{
  //Deallocate memory that element of key
  //fName points to and remove that element from the map.
  delete contents[fName];
  contents.erase(fName);
}

File * Folder::getFile(string fName)
{
  return contents.at(fName);
}

Folder * Folder::openFolder(string fName)
{
  return fCast(contents.at(fName));
}

bool Folder::contains(string fName)
{
  auto it = contents.find(fName);

  if(it == contents.end())
    return false;
  else 
    return true;
}

void Folder::print()
{
  int numElms = 0;
  for(auto it = contents.begin(); it != contents.end(); it++){
     if(numElms > 8)
       cout << endl;

     cout << it->second->get_name() << " ";
     numElms++;
  }

  cout << endl;
}

void Folder::printPerms()
{
  for(auto it = contents.begin(); it != contents.end(); it++){
    if(it->second->is_base())
      cout << "-";                //Field for file identifier
    else
      cout << "d";                //Field for directory identifier

    cout << perms_convert(it->second->get_permissions()) <<" 1 evan evan "
         << rand_file_size(it->second) << " Sep "<< rand_range(5,9) << " " 
         << rand_range(0,23) << ":" << rand_range(10,59) << " " <<it->second->get_name() << endl;
  }
}