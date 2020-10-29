//
// Created by 1285166 on 29.10.2020.
//

#ifndef PARSER_PARS_H
#define PARSER_PARS_H

#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <regex>
#include <exception>

class myexception : public std :: exception{
public:
    myexception(char *excep){
        excepinfo = excep;
    }
    const char* what() const throw() override{
        return excepinfo;
    }
private:
    char *excepinfo;
};

class Parser{
public:
    Parser(std :: string InpFileName);
    ~Parser();
    void find(std :: string el_type, std :: string type_name, std :: string section);
private:
    std :: string fileName = "";
    bool file_is_open = false;
    std :: ifstream file;
    std :: unordered_multimap< std :: string, std :: pair < std :: string , std  :: pair < std :: string , std :: string > > > container;
    void read_sort();
    void space_deleter(std :: string cur_str);

};

#endif //PARSER_PARS_H
