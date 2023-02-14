#ifndef UNTITLED8_VOLUNTAR_H
#define UNTITLED8_VOLUNTAR_H
#include "Persoana.h"
#include "CitireAfisare.h"
class Voluntar : virtual public Persoana{
protected:

    string nr_telefon;
    string sector;
    int puncte_st;
public:
    Voluntar();
    Voluntar(string nume,string cnp,int id,string nr_telefon,string sector,int puncte_st );
    Voluntar(const Voluntar& v);
    Voluntar& operator=(const Voluntar& voluntar);
    istream& citire(istream& in) override;
    ostream& afisare(ostream& out) const override;
    friend istream& operator>>(istream& in, Voluntar& voluntar);
    friend ostream& operator<<(ostream& out, Voluntar& voluntar);
    void setNr_tel(string);
    string getNr_tel() const;
    void setSector(string);
    string getSector() const;
    void setPct(int);
    int getPct() const;
    ~Voluntar() override = default;
};
#endif
