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
    std::cout << "Use: ./euler <problem_id>" << std::endl;
    std::cout << " (If you need help, use --help)" << std::endl;
}

void showHelp()
{
    std::cout << " This program is a simple command line shell that allows an"
              << " user to run solutions to various project euler problems. \n"
              << " All of these solutions were written from scratch by Scott\n"
              << std::endl
              << " To get a list of all available solutions, please use the "
              << " option --list" << std::endl
              << std::endl
              << " For more information about Project Euler, visit:\n"
              << "   http://projecteuler.net" << std::endl
              << std::endl;
}

void showProblemList()
{
    std::map<int, EulerEntry> entries = Registry::singleton().getList();
    std::map<int, EulerEntry>::iterator itr;

    std::cout << "========== Solutions ========================================"
              << std::endl;

    for ( itr = entries.begin(); itr != entries.end(); ++itr )
    {
        std::cout << " " << itr->first << ". "
                  << itr->second.name()
                  << std::endl;
    }
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
