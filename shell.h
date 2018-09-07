#include <queue>

class Shell
{
  private:
    bool running;
    Folder * rootDir;          //Root Directory
    Folder * currDir;          //Current working directory

  public:
    Shell() {running = true; rootDir = new Folder("/user/local/home/sdrive"); currDir = rootDir;}
    ~Shell() {delete rootDir;}

    //Accessors
    bool is_active() {return running;}
    string home() {return rootDir->get_name();}
    string wd() {return currDir->get_name();}
  
    //Operation
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

