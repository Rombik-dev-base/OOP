#include <iostream>
#include "pars.h"


int main() {
    try {
        Parser MyPars("file.ini");

        int found_pos;
        std::string contain = "        Hellow=world    ;sfsdf dsfdsf";
        found_pos = contain.find(';');
        if (found_pos != -1) {
            contain.erase(contain.begin() + found_pos, contain.end());
        }
        while (contain[0] == ' ' || contain[contain.size() - 1] == ' ') {
            if (contain[0] == ' ') {
                contain.erase(0, 1);
            }
            if (contain[contain.size() - 1] == ' ')
                contain.erase(contain.size() - 1, 1);
        }
        std::cout << contain.size() << ' ' << contain;
        found_pos = contain.find('=');
        std::cout << '\n' << ' ' << contain.substr(found_pos + 1, contain.size() - found_pos);
        contain.erase(contain.begin() + found_pos, contain.end());
        std::cout << '\n' << contain << '\n';
        std::string abc = "011.33";
        std::regex reg("[\\-\\+]?[1-9]+[0-9]+.[0-9]+");
        if (std::regex_match(abc.begin(), abc.end(), reg))
            std::cout << " true ";
        MyPars.find("string", "MinVersion", "[Gecko]");
    }
    catch (myexception err)
    {
        std::cout << err.what() << std::endl;
    }
    return 0;
}
