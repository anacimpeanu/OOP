#ifndef UNTITLED8_EXCEPTION_H
#define UNTITLED8_EXCEPTION_H
#include <iostream>
#include <string>
class CNPEXCEPTION:public std::exception{
public:
    virtual const char* what();
};
class NUMEXCEPTION:public std::exception{
public:
    virtual const char* what();
};
class NRTEXCEPTION:public std::exception{
public:
    virtual const char* what();
};
#endif //UNTITLED8_EXCEPTION_H
