//CATCH_CONFIG_RUNNER tells the catch library that this
//project will now explicitly call for the tests to be run.
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "avltree.h"
#include "dsstring.h"
#include "dirent.h"
#include "parse.h"
#include <sys/types.h>
#include <iostream>
#include <cstdlib>
#include "hashtable.h"
#include <fstream>
//A macro used in main to determine if you want to run
//the tests or not. If you don't want to run your tests,
//change true to false in the line below.
//-v input.txt output.txt
#define TEST false


int runCatchTests(int argc, char* const argv[])
{
    //This line of code causes the Catch library to
    //run the tests in the project.
    return Catch::Session().run(argc, argv);
}

int main( int argc, char* const argv[] )
{

    if (TEST)
    {
        return runCatchTests(argc, argv);
    }
    double i=0;
    String BorV=argv[1];
    String dirname=argv[2];
    String outfile=argv[3];//this is the output
    ofstream out(outfile.c_str());
    ifstream fin(dirname.c_str());
    Vector<double> OverallScore1(100);
    double OS1=0;
    double OS2=0;
    double OS3=0;
    double OS4=0;
    double OS5=0;
    double NF=0;
    char file[50];
    fin>>file;
    String filepath(file);
    out<<"Parsing files through Metrics"<<endl;
    Parse p(BorV, filepath, out, true, NF, OS1, OS2,OS3,OS4);
    cout<<"Number of file: "<<NF<<endl;
//    cout<<"Overall Score for Metric1: "<<OS1/NF<<endl;
//    cout<<"Overall Score for CommentCounter: "<<OS2/NF<<endl;
//    cout<<"Overall Score for VariableNames: "<<OS3/NF<<endl;
//    cout<<"Overall Score for Duplication: "<<OS4/NF<<endl;


}
