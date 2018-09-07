#include <queue>

class Shell
{
  private:
    bool running;
    string directory;  //Current working directory

  public:
    Shell() {running = true; directory = "ebmy83";}

    //Shell Operation
    bool is_active() {return running;}
    void exit() {running = false;}
    void selectCommand(queue<string> args);

    //File Management
    

    void pwd();
    void ls();
    void ls_l();
    void cd(string filePath);
    void mkdir(string fName);
    void rmdir(string fName);
    void touch(string fName);
    void rm(string fName);
    void chmod(int perms, string fName);







};

