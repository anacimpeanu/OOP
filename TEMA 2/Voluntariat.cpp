#include <iostream>
#include <string>
#include <utility>
#include "Voluntariat.h"
#include "Student.h"
Voluntariat::Voluntariat() {
    nr=0;
    numeVoluntariat='0';
    locatie='0';
}
Voluntariat::Voluntariat(string nume_,string loc_,int nr_):numeVoluntariat(std::move(nume_)),locatie(std::move(loc_)),nr(nr_) {
    idPersoana++;
}
Voluntariat::Voluntariat(const Voluntariat& voluntariat) {
    numeVoluntariat=voluntariat.numeVoluntariat;
    locatie=voluntariat.locatie;
    nr=voluntariat.nr;
}
Voluntariat& Voluntariat::operator=(const Voluntariat &voluntariat) {
    numeVoluntariat=voluntariat.numeVoluntariat;
    locatie=voluntariat.locatie;
    nr=voluntariat.nr;
    return *this;
}
istream& operator>>(istream&in,Voluntariat& voluntariat){
    cout<<"Introduceti numele voluntariatului : ";
    in>>voluntariat.numeVoluntariat;
    cout<<"Introduceti locatia voluntariatului : ";
    in>>voluntariat.locatie;
    cout<<"Introduceti numarul de persoane care doresc sa se inscrie :";
    in>>voluntariat.nr;
    return in;
}
ostream& operator<<(ostream& out,const Voluntariat& voluntariat) {
    out << "Nume voluntariat este : " << voluntariat.numeVoluntariat;
    out << "Nume locatie este :" << voluntariat.locatie;
    out << "Numarul de persoane inscrise este : " << voluntariat.nr;
    return out;
}
void Voluntariat::setName(std::string nume_) {
    numeVoluntariat=nume_;
}
string Voluntariat::getName() const {
    return numeVoluntariat;
}

void Voluntariat::setLoc(std::string loc_)
{
    locatie=loc_;
}
string Voluntariat::getLoc() const {
    return locatie;
}

void Voluntariat::setNr(int nr_) {
    nr=nr_;
}
int Voluntariat::getNr() const {
    return nr;
}
