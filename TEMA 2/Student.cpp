#include <iostream>
#include <string>
#include "Persoana.h"
#include "Student.h"
using namespace std;
Student::Student():Persoana() {
    facultate = '0';
    nr_matricol = '0';
}
Student::Student(string nume,string cnp,int id,string facultate,string nr_matricol):Persoana(nume,cnp,id)
{
    this->facultate=facultate;
    this->nr_matricol=nr_matricol;
}

Student::Student(const Student &s):Persoana(s){
    facultate=s.facultate;
    nr_matricol=s.nr_matricol;
}

Student& Student::operator=(const Student &s) {
    if(this!=&s){
            Persoana::operator=(s);
            facultate=s.facultate;
            nr_matricol=s.nr_matricol;
    }
    return *this;

}

istream& Student::citire(istream &in){
    Persoana::citire(in);
    cout<<"Introduceti Facultatea :";
    in>>facultate;
    cout<<"Introduceti Numarul matricol al studentului :";
    in>>nr_matricol;
    return in;
}
ostream& Student::afisare(ostream& out) const{
    Persoana::afisare(out);
    out<<"Facultatea este :"<<facultate<<"\n Numarul matricol al studentului este :"<<nr_matricol;
    return out;
}
istream& operator>>(istream& in, Student& s) {
    s.citire(in);
    return in;

}

ostream& operator<<(ostream& out, Student& s) {
    s.afisare(out);
    return out;
}

// Created by Ana Cimpeanu on 12/13/2022.
//
