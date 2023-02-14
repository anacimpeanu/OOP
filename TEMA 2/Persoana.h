#ifndef UNTITLED8_PERSOANA_H
#define UNTITLED8_PERSOANA_H
#include "CitireAfisare.h"
class Persoana : public CitireAfisare{
protected:
    string nume;
    string cnp;
    int id;
public:
    Persoana();
    Persoana(string nume ,string cnp,int id);
    Persoana(const Persoana& p);
    Persoana& operator=(const Persoana& p);
    void setNume(string nume);
    void setCNP(string CNP);
    string getCNP() const;
    string getNume() const;
    friend istream& operator>>(istream& in, Persoana& p);
    friend ostream& operator<<(ostream& out, Persoana& p);
    istream& citire(istream& in) override;
    ostream& afisare(ostream& out) const override;
    void setId(int id);
    virtual ~Persoana() = 0;
};
#endif
