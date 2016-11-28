#ifndef PARSE
#define PARSE
#include "dsstring.h"
#include "dirent.h"
#include <sys/types.h>
#include <iostream>
#include <fstream>
class Parse
{
    public:
        Parse();
        Parse(String&);
    private:


};
#endif // PARSE

Parse::Parse()
{}

Parse::Parse(String& d)
{
    ifstream fin;
    DIR *dirp;
    struct dirent *sd;
    String currFile;
    dirp=opendir(d.c_str());
    char buffer[120];
    if(dirp==NULL)
        cout<<"Not working"<<endl;
    while((sd=readdir(dirp))!=NULL)
    {
        int long td= telldir(dirp);
        cout<<td<<": "<<sd->d_name<<endl;
        currFile = d + "/" + sd->d_name;
        fin.open(currFile.c_str());
        while(!fin.eof())
        {
            fin>>buffer;
            if(buffer[0]=='#')
            {
                String a(buffer);
                cout<<a<<endl;
            }
        }
        fin.close();
    }
    closedir(dirp);
}
