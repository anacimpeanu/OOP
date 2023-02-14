#ifndef UNTITLED8_VOLUNTARIAT_H
#define UNTITLED8_VOLUNTARIAT_H
#include <iostream>
#include <vector>
#include <string>
#include<memory>
#include "Persoana.h"

class Voluntariat{
private:
    string numeVoluntariat;
    string locatie;
    int nr;
    static int idPersoana;
public:
    Voluntariat();
    Voluntariat(string,string,int);
    Voluntariat(const Voluntariat& voluntariat);
    Voluntariat& operator=(const Voluntariat& voluntariat);
    friend istream& operator>>(istream& in,Voluntariat& voluntariat);
    friend ostream& operator<<(ostream& out,const Voluntariat& voluntariat);
    string getName() const;
    string getLoc()const;
    int getNr() const;
    const int getId() const;
    void setName(string);
    void setLoc(string);
    void setNr(int);
    ~Voluntariat(){};
};
#endif //UNTITLED8_VOLUNTARIAT_H
