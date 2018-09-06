#ifndef FILE_H
#define FILE_H

#include <stdexcept>
using namespace std;

class File{
  protected:
    string name;
    int permissions;
    
  public:
    File();
    File(string &nName, int perms) : name(nName), permissions(perms) {}
    File(File &source);
    ~File();
    //Operator =

    //Accessors
    string get_name() {return name;}
    int get_permissions() {return permissions;}

    //Mutators
    void set_name(string & nName) {name = nName;}
    void set_permissions(int & perms) {permissions = perms;} 
};

#include "file.hpp"
#endif