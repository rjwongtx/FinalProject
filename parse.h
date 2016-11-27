#ifndef PARSE
#define PARSE
#include "dsstring.h"
#include "dirent.h"
#include <sys/types.h>
#include <iostream>
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
    DIR *dirp;
    struct dirent *sd;
    dirp=opendir(d.c_str());
    if(dirp==NULL)
    {
        cout<<"Not working"<<endl;
    }
    while((sd=readdir(dirp))!=NULL)
    {
        cout<<sd->d_name<<endl;
    }

    closedir(dirp);

}
