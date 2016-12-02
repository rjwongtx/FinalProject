#ifndef PARSE
#define PARSE
#include "dsstring.h"
#include "dirent.h"
#include "metric1.h"
#include "commentcounter.h"
#include "variablenames.h"
#include "duplication.h"
#include <sys/types.h>
#include <iostream>
#include <fstream>
class Parse
{
    public:
        Parse();
        Parse(String, String&, ofstream&);
        int charlength(char*);
        bool actualFile(char*);
    private:


};
#endif // PARSE

Parse::Parse()
{}

Parse::Parse(String BorV, String& d, ofstream& out)
{
    out<<"Parsing files through Metrics"<<endl;
    DIR *dirp;
    double OS1=0,NF1=0,OS2=0,NF2=0, OS3=0, NF3=0, OS4=0,NF4=0;
    struct dirent *sd;
    dirp=opendir(d.c_str());
    if(dirp==NULL)
        out<<"Not working"<<endl;
    while((sd=readdir(dirp))!=NULL)
    {
      if(actualFile(sd->d_name))
      {
        out<<sd->d_name<<endl;
        String currFile = d + "/" + sd->d_name;
        Metric1 m1(currFile, OS1, NF1, out, BorV);
        CommentCounter c(currFile, OS2, NF2, out, BorV);
        VariableNames v(currFile, OS3, NF3, out, BorV);
        Duplication d(currFile, OS4, NF4, out, BorV);

      }

    }
    out<<"Overall Score for Metric1: "<<OS1/NF1<<endl;
    out<<"Overall Score for CommentCounter: "<<OS2/NF2<<endl;
    out<<"Overall Score for VariableNames: "<<OS3/NF3<<endl;
    out<<"Overall Score for Duplication: "<<OS4/NF4<<endl;

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
