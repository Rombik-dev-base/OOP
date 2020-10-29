#include <iostream>
#include "pars.h"


int main() {
    try {
        Parser MyPars("file.ini");
        MyPars.find("string", "MinVersion", "[Gecko]");
    }
    catch (myexception err)
    {
        std::cout << err.what() << std::endl;
    }
    return 0;
}
