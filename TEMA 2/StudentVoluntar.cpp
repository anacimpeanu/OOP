#include <iostream>
#include <string>
#include "Voluntar.h"
#include "StudentVoluntar.h"
#include "Student.h"
#include "Persoana.h"
using namespace std;
StudentVoluntar::StudentVoluntar() {
    puncte_bonus='0';
    ore='0';
}
StudentVoluntar::StudentVoluntar(string nume,string cnp,int id,string facultate ,string nr_matricol,string nr_telefon,string sector,int puncte_st,int puncte_bonus,int ore):Persoana (nume,cnp,id),Student(facultate,nr_matricol),Voluntar(nr_telefon,sector,puncte_st)
    {
   this->puncte_bonus=puncte_bonus;
   this->ore=ore;
    }
StudentVoluntar::StudentVoluntar(const StudentVoluntar& sa) {
    puncte_bonus=sa.puncte_bonus;
    ore=sa.ore;
}
StudentVoluntar& StudentVoluntar::operator=(const StudentVoluntar& sa){
    Voluntar::operator=(sa);
    puncte_bonus=sa.puncte_bonus;
    ore=sa.ore;
    return *this;
}
istream& StudentVoluntar::citire(std::istream &in) {
    Student::citire(in);
    cout<<"Bonusul fiind student :";
    in>>puncte_bonus;
    cout<<"Numarul de ore pentru voluntariat :";
    in>>ore;
    return in;
}
ostream& StudentVoluntar::afisare(ostream& out) const{
    Student::afisare(out);
    out<<"Punctele bonus sunt : "<<puncte_bonus<<endl;
    out<<"orele lucrate sunt :"<<ore;
    return out;
}
void StudentVoluntar::setPuncte(int pctb_){
    puncte_bonus=pctb_;
}
int StudentVoluntar::getPuncte()  const {
    return puncte_bonus;
}
void StudentVoluntar::setOre(int ore_) {
    ore=ore_;
}
int StudentVoluntar::getOre() const {
    return ore;
}

