#include "utils.h"
#include <string>
#include <sstream>

bool parseInt( const std::string& in, int& out )
{
    std::stringstream ss( in );

    bool bSuccess = false;
    int result;

    if (! (ss >> result).fail() )
    {
        bSuccess = true;
        out      = result;
    }

    return bSuccess;
}
