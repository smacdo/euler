#include "projecteuler.h"
#include <cmath>

#include <iostream>
#include <vector>
#include <string>

REGISTER_PROBLEM(9, "Find pythagorean triple a+b+c=1000")

void problem_9( const std::vector<std::string>& args )
{
    bool bAnswer = false;

    for ( int a = 1; a < 1000 && !bAnswer; ++a )
    {
        for ( int b = 1; b < 1000; ++b )
        {
            if ( a + b + sqrt( a*a + b*b ) == 1000 )
            {
                int c = sqrt( a*a + b*b );

                std::cout << "a=" << a << std::endl;
                std::cout << "b=" << b << std::endl;
                std::cout << "c=" << c << std::endl;
                std::cout << "abc=" << a * b * c << std::endl;

                bAnswer = true;
                break;
            }
        }
    }

    if (! bAnswer )
    {
        std::cerr << "Failed to find a solution" << std::endl;
    }
}

