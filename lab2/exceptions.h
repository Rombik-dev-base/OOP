//
// Created by 1285166 on 30.10.2020.
//

#ifndef SHOP__EXCEPTIONS_H
#define SHOP__EXCEPTIONS_H
#include <exception>

class my_exception : public std :: exception{
public:
    my_exception(char *excep){
        excepinfo = excep;
    }
    const char* what() const throw() override{
        return excepinfo;
    }
private:
    char *excepinfo;
};

#endif //SHOP__EXCEPTIONS_H
