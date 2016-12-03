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
        Parse(String, String&, ofstream&, bool, double&, double&,double&,double&,double&,double&);
        int charlength(char*);
        bool actualFile(char*);
    private:


};
#endif // PARSE

Parse::Parse()
{}

Parse::Parse(String BorV, String& d, ofstream& out, bool option, double& NF, double& OS1, double& OS2,double& OS3,double& OS4,double& OS5)
{
    double na=0;
    DIR *dirp;
    struct dirent *sd;
    dirp=opendir(d.c_str());
    if(dirp==NULL)
        out<<"Not working"<<endl;
    while((sd=readdir(dirp))!=NULL)
    {
      DIR *dirp2;
      String temp = d + "/" + sd->d_name;
      if(sd->d_name[0]!='.')
      {
          dirp2=opendir(temp.c_str());
          if(dirp2!=NULL)
              Parse q(BorV, temp, out, false, NF, OS1, OS2,OS3,OS4,OS5);
          else
              closedir(dirp2);
      }

      if(actualFile(sd->d_name))
      {
        out<<sd->d_name<<endl;
        String currFile = d + "/" + sd->d_name;
        Metric1 m1(currFile, OS1, NF, out, BorV);
        CommentCounter c(currFile, OS2, na, out, BorV);
        VariableNames v(currFile, OS3, na, out, BorV);
        Duplication d(currFile, OS4, na, out, BorV);

      }

    }
    if(option)
    {
        out<<"Overall Score for Metric1: "<<OS1/NF<<endl;
        out<<"Overall Score for CommentCounter: "<<OS2/NF<<endl;
        out<<"Overall Score for VariableNames: "<<OS3/NF<<endl;
        out<<"Overall Score for Duplication: "<<OS4/NF<<endl;
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
