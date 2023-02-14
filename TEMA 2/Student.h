#include "Persoana.h"
#include "CitireAfisare.h"
using namespace std;
class Student : public Persoana{
private:

    string facultate;
    string nr_matricol;

public:
    Student();
    Student(string nume,string cnp, int id, string facultate, string nr_matricol);
    Student(const Student &s);
    Student& operator=(const Student &s);
    friend istream& operator>>(istream& in, Student& s);
    friend ostream& operator<<(ostream& out, Student& s);
    istream& citire(istream& in) override;
    ostream& afisare(ostream& out) const override;

    ~Student() override= default;;

};

