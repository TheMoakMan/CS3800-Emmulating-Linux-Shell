#include <iostream>
#include "file.h"
#include "folder.h"

using namespace std;

File * makeFile(string name, int perms);
File * makeFolder(string name, int perms);

int main()
{
  cout << "Test for compilation" << endl;
  cout << "Building a Folder: ";
  Folder sDrive("sDrive", 777);
  cout << sDrive.get_name() << endl;

  sDrive.addFile(makeFile("moak.txt", 777));
  sDrive.addFile(makeFile("jacques.txt", 777));
  sDrive.addFile(makeFile("WrathOFDavid.exe", 777));
  sDrive.addFile(makeFile("LivLastDay.txt", 777));
  
  sDrive.rmFile("moak.txt");
  
  sDrive.addFile(makeFolder("MY STUFF", 777));

  File * newFolder = sDrive.openFolder("MY STUFF");
  sDrive.print();

  cout << endl << endl;
  //cout << newFolder->get_name() << endl;

  
  return 0;
}