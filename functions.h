#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <sstream>
#include "folder.h"
#include "shell.h"

//File And Folder manipulation
File * makeFile(string name);
File * makeFolder(string name);
Folder * fCast(File * f);

//Shell interaction
void run_shell();
queue<string> get_input();

#endif