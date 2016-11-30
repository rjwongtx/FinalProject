#ifndef COMMENTCOUNTER
#define COMMENTCOUNTER
#include "dsstring.h"
class CommentCounter
{
    public:
        CommentCounter(String, double&, double&, ofstream&);
};
#endif // COMMENTCOUNTER

CommentCounter::CommentCounter(String d, double& OS, double& NF, ofstream& out)
{
    double score=0;
    double comments=0;
    int lineCount=0;
    char buffer[500]={'\0'};
    ifstream fin;
    fin.open(d.c_str());
    while(!fin.eof())
    {
        fin.getline(buffer, 500);
        if(buffer[0]!='\0')
            lineCount++;
    }
    cout<<"Line Count: "<<lineCount<<endl;
    fin.close();

    fin.open(d.c_str());
    while(!fin.eof())
    {
        fin>>buffer;
        for(int i=0; i<100; i++)
        {
            if(buffer[i]=='/' && buffer[i+1]=='/')
            {
                comments++;
                break;
            }
            else if(buffer[i]=='\0')
                break;
            else
                continue;
        }
    }
    fin.close();
    cout<<"Comment Count: "<<comments<<endl;
    if(comments==0)
        score=10;
    else
        score = lineCount/comments;
    OS+=score;
    NF++;
    cout<<"Score for Metric2 at this file: "<<score<<endl;
    cout<<"---------------------------------"<<endl;


}