# CS3800-Emmulating-Linux-Shell

This program was written to emulate a linux command shell to the extent of performing a specific
set of instructions. 

Please run this program either using the makefile provided with the command $make program 
or using the g++ compiler with flags set for c++ 11. Executable will be named program.

Input is set to be read in the same was that a linux shell reads in input, with the enter key being
the end of a command statement. Invalid input will be addressed. Support for Quotes on arguments to skip
whitespace is not yet integrated.

List of valid commands:
    $pwd
    $exit
    $quit
    $mkdir <filename>        #Can input more than 1 argument
    $ls
    $ls -l
    $rm <filename>           #Can input more than 1 argument
    $rmdir <filename>        #Can input more than 1 argument
    $touch <filename>        #Can input more than 1 argument
    $cd <filename>           #Only 1 argument and does not support filepaths
    $cd ..
    $chmod <intger> <filename>
    $vim <filename>          #Runs Vim text editer from system and opens a file of the given name
    $sudo apt install <name> #DO NOT RECOMEND WITHOUT ADMIN PRIVILEDGES
    $make sandwich           #Try it, its fun.

If program code for some reason is missing in does not run,
the program is also saved to the git repository: https://github.com/TheMoakMan/CS3800-Emulating-Linux-Shell.git


  

