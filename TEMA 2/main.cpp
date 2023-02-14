#include <iostream>
#include "Voluntariat.h"
#include "StudentVoluntar.h"
#include "Persoana.h"
#include "Voluntar.h"
#include "Student.h"
using namespace std;
int main(){
    Voluntariat *v;
    vector<Persoana*> persoane;

    int opt=0;
    do{
        cout<<" CIMPEANU ANA_MARIA // GRUPA 264 // TEMA 2 \n";
        cout<<"Pentru a utiliza o functie a meniului ,tastati cifra corespunzatoare \n";
        cout<<"1.Adaugare persoane care doresc sa se inscrie la voluntariat \n";
        cout<<"2.Afisare persoane care s-au inscris la voluntariat\n";
        cout<<"3.Afisare studentii inscrisi\n";
        cout<<"4.Afisare voluntarii participanti \n";
        cout<<"5.Afisare voluntarii care sunt si studenti \n:";
        cout<<"6.Afiseaza toate datele voluntariatului\n";
        cout<<"0.Pentru iesire din comanda\n";
        cout<<"\n\n Optiunea aleasa este :";
        cin>>opt;
        switch(opt){
            case 1: {
                cout << "Selecteaza ce tip de participant vrei sa adaugi [student/voluntar/StudentVoluntar]";
                string tip;
                cin >> tip;
                if (tip == "student") {
                    Student student;
                    cin >> student;
                    persoane.push_back(new Student(student));
                } else if (tip == "voluntar") {
                    Voluntar voluntar;
                    cin >> voluntar;
                    persoane.push_back(new Voluntar(voluntar));
                } else if (tip == "StudentVoluntar") {
                    StudentVoluntar studentVoluntar;
                    cin >> studentVoluntar;
                    persoane.push_back(new StudentVoluntar(studentVoluntar));
                } else cout << "Comanda invalida!\n";
                cout << "\n\n";
                break;
            }
            case 2: {
                for (const auto &i: persoane)
                    cout << *i;
                cout << "\n\n";
                break;
            }
            case 3: {
                for (const auto &i: persoane)
                    if (!dynamic_cast<StudentVoluntar *>(const_cast<Persoana *>(i)))
                        if (dynamic_cast<Student *>(const_cast<Persoana *>(i)))
                            cout << *i;
                cout << "\n\n";
                break;
            }
            case 4: {
                for (const auto &i: persoane)
                    if (!dynamic_cast<StudentVoluntar *>(const_cast<Persoana *>(i)))
                        if (dynamic_cast<Voluntar *>(const_cast<Persoana *>(i)))
                            cout << *i;
                cout << "\n\n";
                break;
            }
            case 5: {
                for (const auto &i: persoane)
                    if (dynamic_cast<StudentVoluntar *>(const_cast<Persoana *>(i)))
                        cout << *i;
                cout << "\n\n";
                break;
            }
            case 6: {
                cout << v;
                break;
            }
            case 0: {
                exit(0);
                break;
            }
            default:
                cout<<"\n Optiunea invalida !";
        }
    }while(opt!=0);
    return 0;
}
