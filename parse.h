#ifndef PARSE
#define PARSE
#include "dsstring.h"
#include "dirent.h"
#include "metric1.h"
#include <sys/types.h>
#include <iostream>
#include <fstream>
class Parse
{
    public:
        Parse();
        Parse(String&);
        int charlength(char*);
        bool actualFile(char*);
    private:


};
#endif // PARSE

Parse::Parse()
{}

Parse::Parse(String& d)
{

    DIR *dirp;
    struct dirent *sd;
    dirp=opendir(d.c_str());

    if(dirp==NULL)
        cout<<"Not working"<<endl;
    while((sd=readdir(dirp))!=NULL)
    {
      if(actualFile(sd->d_name))
      {
        cout<<sd->d_name<<endl;
        String currFile = d + "/" + sd->d_name;
        Metric1 m1(currFile);
      }

    }
    closedir(dirp);
}

int Parse::charlength(char* dname)
{
    for(int i=0; i<20; i++)
    {
        if (dname[i]=='\0')
            return i;
    }
}

bool Parse::actualFile(char* sd)
{
    bool yes;
    if(sd[charlength(sd)-1]=='h')
        yes=true;
    else if(sd[charlength(sd)-1]=='p'&&sd[charlength(sd)-2]=='p'&&sd[charlength(sd)-3]=='c')
        yes=true;
    else if(sd[charlength(sd)-1]=='p'&&sd[charlength(sd)-2]=='p'&&sd[charlength(sd)-3]=='h')
        yes=true;
    else if(sd[charlength(sd)-1]=='c')
        yes=true;
    else
        yes=false;
}
