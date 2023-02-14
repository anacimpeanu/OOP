#ifndef UNTITLED8_STUDENTVOLUNTAR_H
#define UNTITLED8_STUDENTVOLUNTAR_H
#include "Student.h"
#include "Voluntar.h"
#include "CitireAfisare.h"
class StudentVoluntar:public Student,public Voluntar{
private:
    int puncte_bonus; //se primeste un bonus daca voluntarul este student
    int ore;
public:
    StudentVoluntar();
    StudentVoluntar(const string& nume,string cnp,int id,string facultate ,string nr_matricol,string nr_telefon,string sector,int puncte_st,int puncte_bonus,int ore);
    StudentVoluntar(const StudentVoluntar& sa);
    StudentVoluntar& operator=(const StudentVoluntar& sa);
    istream& citire(istream& in) override;
    ostream& afisare(ostream& out) const override;
    friend istream& operator>>(istream& in, StudentVoluntar& sa);
    friend ostream& operator<<(ostream& out, StudentVoluntar& sa);

    void setPuncte(int);
    int getPuncte() const;
    void setOre(int);
    int getOre() const;
    ~StudentVoluntar() override= default;;

};
#endif //UNTITLED8_STUDENTVOLUNTAR_H
