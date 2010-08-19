#include <iostream>

int main( int argc, char* argv[] )
{
    // project 1
    int sum = 0;

    for ( int i = 1; i < 1000; ++i )
    {
        if ( i % 3 == 0 || i % 5 == 0 )
        {
            sum += i;
        }
    }

    std::cout << "the result is: " << sum << std::endl;
}
