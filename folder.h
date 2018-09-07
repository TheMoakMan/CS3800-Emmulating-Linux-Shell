#ifndef FOLDER_H
#define FOLDER_H

#include <iostream>
#include "file.h"
#include <map>

using namespace std;


class Folder: public File{
    private:
      /*
        Inherited from File:
          string name;
          int permissions;
      */
       
       //Containter to hold the conents of the directory, 
       //Can hold files or other folders.
       map<string, File *> contents; 
       
    public:
      /*
        Inherited from File:
          string get_name();
          int get_permissions();
          void set_name(string & nName);
          void set_permissions(int & perm);
      */

      Folder() {}
      Folder(string nName, int perms) : File(nName, perms) {}
      Folder(Folder &source);
      ~Folder();

      //Contents Modifiers
      void addFile(File * source);
      void rmFile(string fName);
      Folder * openFolder(string fName);
      
      void print();
};

#endif