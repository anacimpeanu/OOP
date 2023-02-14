#ifndef UNTITLED8_CITIREAFISARE_H
#define UNTITLED8_CITIREAFISARE_H
#include <iostream>
using namespace std;
class CitireAfisare {
public:
    virtual istream& citire(istream& in) = 0;
    virtual ostream& afisare(ostream& out) const = 0;
};
#endif
