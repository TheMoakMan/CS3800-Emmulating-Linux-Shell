#include <iostream>
#include "functions.h"

using namespace std;

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

  sDrive.print();

  cout << endl;
  Folder * newFolder = sDrive.openFolder("MY STUFF");
  
  File * nFolder = newFolder;
  newFolder = nullptr;
  fCast(nFolder)->addFile(makeFile("John Cena.txt",777));
  fCast(nFolder)->print();

  return 0;
}

