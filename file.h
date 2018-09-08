#ifndef FILE_H
#define FILE_H

#include <stdexcept>
using namespace std;

class File{
  protected:
    string name;
    int permissions;
    bool is_base_file = true;    //flag to check if a given file is base file or a folder.
    
  public:
    File() {}
    File(string nName) : name(nName), permissions(777) {}
    File(File &source);
    //Operator =

    //Accessors
    string get_name() {return name;}
    int get_permissions() {return permissions;}
    bool is_base() {return is_base_file;}

    //Mutators
    void set_name(string & nName) {name = nName;}
    void set_permissions(int & perms) {permissions = perms;} 
};

//#include "file.hpp"
#endif