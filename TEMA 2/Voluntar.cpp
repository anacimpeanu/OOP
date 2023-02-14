#include <iostream>
#include <string>
#include "Voluntar.h"
#include "Exception.h"
using namespace  std;
Voluntar::Voluntar():Persoana(){
    nr_telefon='0';
    sector='0';
    puncte_st=0;
}
Voluntar::Voluntar(string nume,string cnp,int id,string nr_telefon,string sector,int puncte_st,int ore):Persoana(string nume,string cnp,int id){
    this->nr_telefon=nr_telefon;
    this->sector=sector;
    this->puncte_st=puncte_st;
}
Voluntar::Voluntar(const Voluntar& v):Persoana(v){
    nr_telefon=v.nr_telefon;
    sector=v.sector;
    puncte_st=v.puncte_st;
}
Voluntar& Voluntar::operator=(const Voluntar &v) {
    if(this!=&v) {
        Persoana::operator=(v);
        nr_telefon = v.nr_telefon;
        sector = v.sector;
        puncte_st = v.puncte_st;
    }
    return *this;

}
istream& Voluntar::citire(istream& in){
    Persoana::citire(in);
    while (nr_telefon =="0"){
        cout << "\nIntroduceti numarul de telefon romanesc : ";
        in >>nr_telefon;
        try{
            if (nr_telefon.length() != 10)
                throw NRTEXCEPTION();
        }
        catch (exception& e){
            cout << e.what() << endl;
            cout << "Numarul de telefon romanesc are doar 10 cifre\n";
            nr_telefon = "0";
        }

    }
    cout<<"\n Introduceti sectorul :";
    in>>sector;
    cout<<"\n Introduceti punctele standart :";
    in>>puncte_st;
    return in;
}
ostream& Voluntar::afisare(ostream& out )const{
    Persoana::afisare(out);
    out<<"Numarul de telefon este :"<<nr_telefon<<"Sectorul este : "<<sector<<"Puctele standart sunt "<<puncte_st<<endl;
    return out;
}
void Voluntar::setNr_tel(string nr_telefon_) {
    nr_telefon=nr_telefon_;
}
string Voluntar::getNr_tel()const {
    return nr_telefon;
}
void Voluntar::setSector(string sector_){
    sector=sector_;
}
string Voluntar::getSector() const {
    return sector;
}
void Voluntar::setPct(int pct_) {
    puncte_st=pct_;
}
float Voluntar::getPct() const {
    return puncte_st;
}

