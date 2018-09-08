#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <sstream>
#include <random>
#include <ctime>
#include "folder.h"
#include "shell.h"

//File And Folder manipulation
File * makeFile(string name);
File * makeFolder(string name, Folder * parent);
Folder * fCast(File * f);
string perms_convert(int perms);

//Shell interaction
void run_shell();
queue<string> get_input();
bool valid_int_str(string str);

//Extra Functionality
int rand_file_size(File * fl);
int rand_range(int low, int up);

#endif