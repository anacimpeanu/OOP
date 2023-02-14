#include <iostream>
#include <string>
#include <utility>
#include "Persoana.h"
#include "Exception.h"
Persoana::Persoana() {
    id=0;
    nume = "0";
    cnp = "0";
}

Persoana::Persoana(string nume,string cnp,int id) {
    this->nume=nume;
    this->cnp=cnp;
    this->id=id;
}

Persoana::Persoana(const Persoana& p) {
    nume=p.nume;
    cnp=p.cnp;
    id=p.id;
}

Persoana& Persoana::operator=(const Persoana& p) {
    nume=p.nume;
    cnp=p.cnp;
    id=p.id;
    return *this;
}

void Persoana::setNume(string nume_) {
    nume = nume_;
}

string Persoana::getNume() const {
    return nume;
}

void Persoana::setCNP(string CNP_) {
    cnp= std::move(CNP_);
}

string Persoana::getCNP() const {
    return cnp;
}
istream& Persoana::citire(istream& in) {
    while(nume =="0"){
        cout << "Introduceti numele persoanei : ";
        in>>nume;
        try{
            for(char i : nume)
                if (!(isalpha(i)) && i != '0')
                    throw NUMEXCEPTION();

        }
        catch(exception& e){
            cout<<e.what()<<endl;
            cout<<"Numele poate contine doar spatii si litere !\n";
            nume='0';
        }
    }
    while (cnp =="0"){
        cout << "\nIntroduceti CNP-ul persoanei: ";
        in >>cnp;
        try{
            if (cnp.length() != 13)
                throw CNPEXCEPTION();
        }
        catch (exception& e){
            cout << e.what() << endl;
            cout << "CNP-ul are 13 cifre\n";
            cnp = "0";
        }
    }

    return in;
}

ostream& Persoana::afisare(ostream& out) const{
    out<<"\nID: "<<id<<"\n NUME: "<<nume<<"\nCNP: "<<cnp;
    return out;
}

istream& operator>>(istream& in, Persoana& p) {
    p.citire(in);
    return in;

}

ostream& operator<<(ostream& out, Persoana& p) {
    p.afisare(out);
    return out;
}
void Persoana::setId(int id_) {
    id=id_;
}
Persoana::~Persoana() {
    id=0;
    nume='0';
    cnp='0';
}

