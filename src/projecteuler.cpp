#include "projecteuler.h"
#include "utils.h"

#include <string>
#include <vector>
#include <cassert>
#include <iostream>

void showUse();
void showHelp();
void showProblemList();
int runProblem( int id, const std::vector<std::string>& args );

int main( int argc, char* argv[] )
{
    //
    // Parse program arguments
    //
    std::string firstArg;
    std::vector<std::string> args;
    
    if ( argc < 2 )
    {
        showUse();
        return 0;
    }

    firstArg = argv[1];

    for ( int i = 2; i < argc; ++i )
    {
        args.push_back( argv[i] );
    }

    //
    // Use the argument to figure out just what we're supposed to be doing
    //
    if ( firstArg == "--help" )
    {
        showHelp();
    }
    else if ( firstArg == "--list" )
    {
        showProblemList();
    }
    else
    {
        int id = 0;

        if (! parseInt( firstArg, id ) )
        {
            std::cerr << "Invalid problem id" << std::endl;
            return -1;
        }
        else
        {
            return runProblem( id, args );
        }
    }
}

void showUse()
{
    std::cout << "--use---" << std::endl;
}

void showHelp()
{
    std::cout << "help goes here" << std::endl;
}

void showProblemList()
{
    std::cout << "===== List of problems =====" << std::endl;
}

int runProblem( int id, const std::vector<std::string>& args )
{
    //
    // Does this problem exist?
    //
    if (! Registry::singleton().has( id ) )
    {
        std::cerr << "No such problem id" << std::endl;
        return 1;
    }

    //
    // Get it and run it!
    //
    EulerEntry entry = Registry::singleton().get( id );
    assert( entry.func() != 0 );

    std::cout << "----- Starting -----" << std::endl;

    long result = entry.func()( args );
    
    std::cout << " Result: " << result  << std::endl;
    std::cout << "----- All done -----" << std::endl;

    return 0;
}
