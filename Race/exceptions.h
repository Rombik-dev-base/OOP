//
// Created by 1285166 on 13.11.2020.
//

#ifndef RACE_EXCEPTIONS_H
#define RACE_EXCEPTIONS_H
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

#endif //RACE_EXCEPTIONS_H
