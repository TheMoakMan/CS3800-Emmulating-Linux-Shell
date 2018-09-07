#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "folder.h"
#include "shell.h"
#include <queue>

//File And Folder manipulation
File * makeFile(string name, int perms);
File * makeFolder(string name, int perms);
Folder * fCast(File * f);

//Shell interaction
void run_shell();

#endif