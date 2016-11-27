//CATCH_CONFIG_RUNNER tells the catch library that this
//project will now explicitly call for the tests to be run.
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "avltree.h"
#include "dsstring.h"
#include "vector.h"
#include "dirent.h"
#include "parse.h"
#include <sys/types.h>
#include <iostream>
#include <cstdlib>
#include "hashtable.h"
//A macro used in main to determine if you want to run
//the tests or not. If you don't want to run your tests,
//change true to false in the line below.
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
    String test = get_current_dir_name();
    String dirname=argv[1];
    Parse p(dirname);

}