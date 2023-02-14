#include <iostream>
#include <cstring>
using namespace std;
class Student {
private:

    char *nume;
    char *prenume;
    char *forma_finantare;
    int nr_credite;
    int nr_matricol;
public:
    //constructori
    //constructor de intializare
    Student();
    //constructor cu parametrii
    Student(char *nume,char *prenume, char *forma_finantare,int nr_credite, int nr_matricol);

    //copy constructor
    Student(const Student &s);
    //citire
    friend istream &operator>>(istream& in, Student& s);

    //afisare
    friend ostream &operator<<(ostream& out, const Student& s);

    //supraincarcarea de operatori
    Student &operator=(const Student& s);

    bool operator==(const Student& s);
    bool operator!=(const Student& s);

    //setter
    void setNume(char *nume);

    void setPrenume(char *prenume);

    void setFormafinantare(char *forma_finantare);

    void setNrCredite(int nr_credite);

    void setNrMatricol(int nr_matricol);

    //getter
    char *getNume() const;

    char *getPrenume() const;

    char *getFormafinantare() const;

    int getNrCredite() const;

    int getNrMatricol() const;

    //destructor
    ~Student();

};
//operator !=
bool Student::operator != (const Student& s){
    if (strcmp(this->nume, s.nume) != 0 )
        if(strcmp(this->prenume, s.prenume)!=0)
            if( strcmp(this->forma_finantare,s.forma_finantare)!=0)
                if(this->nr_credite!= s.nr_credite)
                    if( this->nr_matricol !=s.nr_matricol)
                        return true;
    return false;
}

int strcmp(bool b);

//in clion mi s-a creat functia strcmp
//pentru elemente tip char , compar lungimea
//operator ==
bool Student::operator==(const Student& s){
    if(strcmp(this->nume==s.nume)==0)
        if(strcmp(this->prenume==s.prenume)==0)
            if(strcmp(this->forma_finantare==s.forma_finantare)==0)
                if(this->nr_credite==s.nr_credite)
                    if(this->nr_matricol==s.nr_matricol)
                        return true;
    return false;
}

int strcmp(bool b) {
    return 0;
}

Student& Student::operator=(const Student& s){
    if(this!=&s) {
        //se verifica adresele de memorie
        if (this->nume != NULL)
            delete[] this->nume;    //daca exista memorie ocupata, se sterge
         //se realoca memorie
        this->nume=new char[strlen(s.nume)+1];
        //ne ajutam de functia strlen pentru a aloca destula memorie (in caz bun,numarul de caractere a numarului) + 1 (\n)
        strcpy(this->nume,s.nume);
        //se copiaza la adresa (this->nume ) s.nume
        if (this->prenume != NULL)
            delete[] this->prenume;
        this->prenume=new char[strlen(s.prenume)+1];
        strcpy(this->prenume,s.prenume);
        if (this->forma_finantare)
            delete[] this->forma_finantare;
        this->forma_finantare=new char[strlen(s.forma_finantare)+1];
        strcpy(this->forma_finantare,s.forma_finantare);
        this->nr_matricol = s.nr_matricol;
        this->nr_credite = s.nr_credite;
    }
    return *this;

}
istream& operator>>(istream& in,Student& s){
    cout<<"\nDati numele studentului";
    char aux[100];
    in>>aux;
    if(s.nume!=NULL)
        delete[] s.nume;
    s.nume=new char[strlen(aux)+1];
    strcpy(s.nume,aux);
    cout<<"\nDati prenumele studentului";
    in>>aux;
    if(s.prenume!=NULL)
        delete[] s.prenume;
    s.prenume=new char[strlen(aux)+1];
    strcpy(s.prenume,aux);
    cout<<"\nDati forma de finantare a studentului";
    in>>aux;
    if(s.forma_finantare!=NULL)
        delete[] s.forma_finantare;
    s.forma_finantare=new char[strlen(aux)+1];
    strcpy(s.forma_finantare,aux);
    cout<<"\nDati numarul matricol al studentului";
    in>>s.nr_matricol;
    cout<<"\nDati numarul de credite al studentului";
    in>>s.nr_credite;
    return in;
}
ostream& operator<<(ostream& out,const Student& s){
    out<<"\nNumele studentului este "<<s.nume;
    out<<"\nPrenumele studentului este "<<s.prenume;
    out<<"\nForma de finantare este "<<s.forma_finantare;
    out<<"\nNumarul matricol al studentului este "<<s.nr_matricol;
    out<<"\nNumarul de credite al studentului este "<<s.nr_credite;
    out<<endl;
    return out;
}

Student::Student(const Student& s) {
    this->nume= new char[strlen(s.nume)+1];
    strcpy(this->nume, s.nume);
    this->prenume= new char[strlen(s.prenume)+1];
    strcpy(this->prenume, s.prenume);
    this->forma_finantare= new char[strlen(s.forma_finantare)+1];
    strcpy(this->forma_finantare, s.forma_finantare);
    this->nr_matricol = s.nr_matricol;
    this->nr_credite = s.nr_credite;
}
Student::Student(char* nume,char* prenume, char* forma_finantare,int nr_matricol,int nr_credite){
    this->nume= new char[strlen(nume)+1];
    strcpy(this->nume, nume);
    this->prenume= new char[strlen(prenume)+1];
    strcpy(this->prenume, prenume);
    this->forma_finantare= new char[strlen(forma_finantare)+1];
    strcpy(this->forma_finantare,forma_finantare);
    this->nr_matricol = nr_matricol;
    this->nr_credite=nr_credite;

}
Student::Student() {
    // se aloca spatiu pentru variabila
    this->nume = new char[strlen("Anonim")+1];
    strcpy(this->nume, "Anonim");
    this->prenume = new char[strlen("Anonim")+1];
    strcpy(this->prenume, "Anonim");
    this->forma_finantare = new char[strlen("Anonim")+1];
    strcpy(this->forma_finantare, "Anonim");
    this->nr_matricol =0;
    this->nr_credite=0;
}
Student::~Student() {
    if (this->nume != NULL)
        delete [] this->nume;
    if (this->prenume != NULL)
        delete [] this->prenume;
    if (this->forma_finantare!=NULL)
        delete [] this->forma_finantare;
}

void Student::setNume(char *nume) {
    if (this->nume != NULL)
        delete[] this->nume;
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
}

void Student::setPrenume(char *prenume) {
    if (this->prenume != NULL)
        delete[] this->prenume;
    this->prenume = new char[strlen(prenume) + 1];
    strcpy(this->prenume, prenume);
}
void Student::setFormafinantare(char *forma_finantare) {
    if (this->forma_finantare != NULL)
        delete[] this->forma_finantare;
    this->forma_finantare = new char[strlen(forma_finantare) + 1];
    strcpy(this->forma_finantare, forma_finantare);
}
void Student::setNrMatricol(int nr_matricol) {
    this->nr_matricol = nr_matricol;
}
void Student::setNrCredite(int nr_credite) {
    this->nr_credite=nr_credite;
}
char *Student::getNume() const {
    return nume;
}

char *Student::getPrenume() const {
    return prenume;
}
char *Student::getFormafinantare() const {
    return forma_finantare;
}

int Student::getNrMatricol() const {
    return nr_matricol;
}
int Student::getNrCredite() const {
    return nr_credite;
}
class Grupa {
private:
    int nr_grupa;
    int nr_studenti;
    Student *listaStudenti;
public:
    //constructor fara parametru
    Grupa();

    //constructor cu toti parametrii
    Grupa(int nr_grupa, int nr, Student *listaStud);

    //copy constructor
    Grupa(const Grupa &g);

    //supraincarcarea operatorului =
    Grupa &operator=(const Grupa &g);

    //supraincarcarea operatorului ==
    bool operator==(const Grupa &g);

    //Setter
    void setListaStudenti(int nr, Student *listaStudenti);

    int setNr(int nr_grupa);

    //getter
    int getNr() const;

    int getNrStudenti() const;

    Student getlistaStudenti(int i) const;

    //afisare
    friend ostream &operator<<(ostream& out, const Grupa& g);

    friend istream &operator>>(istream& in, Grupa& g);

    //adaugarea unui student in grupa
    friend Grupa &operator+=(Grupa& g, const Student& s);

    //cautarea unui student in grupa dupa nume si prenume
    void cautareStudent(const Student& s);

    ~Grupa();
};
bool Grupa::operator==(const Grupa &g){
    if(this->nr_grupa==g.nr_grupa)
        if(this->nr_studenti==g.nr_studenti)
            for(int i=0;i<this->nr_studenti;i++)
                if(this->listaStudenti[i] == g.listaStudenti[i])
                    return true;
    return false;
}
Grupa& operator+=(Grupa& g,const Student& s){
    //copie lista
    Student* listaAux=new Student[g.nr_studenti];
    for (int i = 0; i < g.nr_studenti; i++) {
        listaAux[i] = g.listaStudenti[i];
    }

    //dezaloc memorie
    if(g.listaStudenti)
        delete [] g.listaStudenti;
    g.nr_studenti++;
    g.listaStudenti=new Student[g.nr_studenti];
    for(int i=0;i<g.nr_studenti-1;i++)
        g.listaStudenti[i]=listaAux[i];
    Student *new_student= new Student(s);
    g.listaStudenti[g.nr_studenti-1]=*new_student;
    if(listaAux)
        delete [] listaAux;
    return g;
}

Grupa& Grupa::operator=(const Grupa& g){
    int i;
    if(this!=&g){
        if(this->listaStudenti)
            delete [] this->listaStudenti;
        this->nr_studenti=g.nr_studenti;
        this->nr_grupa=g.nr_grupa;
        this->listaStudenti=new Student[g.nr_studenti];
        for(int i=0;i,g.nr_studenti;i++)
            this->listaStudenti[i]=g.listaStudenti[i];
    }
    return *this;
}
istream& operator >> (istream& in, Grupa& g){
    cout << "\nDati numarul grupei :" ;
    in >> g.nr_studenti;
    cout << "\nDati nr de studenti:";
    in>> g.nr_studenti;
    cout << "\nIntroduceti " << g.nr_studenti<< " studenti \n";
    if (g.listaStudenti!=0)
        delete [] g.listaStudenti;
    g.listaStudenti = new Student[g.nr_studenti];
    for (int i=0; i<g.nr_studenti; i++)
        in>> g.listaStudenti[i];
    return in;
}
ostream& operator << (ostream& out, const Grupa& g){
    out << "Numarul grupei este " << g.nr_grupa << endl;
    out << "Grupa are : " << g.nr_studenti<< " studenti\n";
    for (int i=0; i<g.nr_studenti; i++)
        out << g.listaStudenti[i] << endl;
    return out;
}
Grupa::Grupa(const Grupa& g){
    this->nr_grupa=g.nr_grupa;
    this->nr_studenti = g.nr_studenti;
    //alocare spatiu
    this->listaStudenti = new Student[this->nr_studenti];
    for(int i =0; i<g.nr_studenti; i++)
        this->listaStudenti[i] = g.listaStudenti[i];

}
Grupa::Grupa(int nr_grupa, int nr, Student *listaStud) {
    this->nr_grupa=nr_grupa;
    this->nr_studenti = nr;
    this->listaStudenti= new Student[nr];
    for (int i = 0; i<this->nr_studenti; i++)
        this->listaStudenti[i] = listaStud[i];
}
Grupa::Grupa() {
    this->nr_grupa=0;
    this->nr_studenti = 0;
    this->listaStudenti= NULL;
}
Grupa::~Grupa() {
    if(this->listaStudenti)
        delete [] this->listaStudenti;
}
int Grupa::setNr(int nr_grupa){
    this->nr_grupa=nr_grupa;
}
void Grupa::setListaStudenti(int nr, Student *listaStud) {
    int i;
    this->nr_studenti=nr;
    //verificare spatiu
    if(this->listaStudenti)
        delete[] this->listaStudenti;
    //alocare spatiu
    this->listaStudenti=new Student[nr];
    for(i=0;i<nr;i++)
        this->listaStudenti[i]=listaStud[i];
}
void Grupa::cautareStudent(const Student &s) {
    int i;
    for(i=0;i<this->nr_studenti;i++)
        if(this->listaStudenti[i]==s){
            cout<<"Studentul "<<s.getNume()<<" "<<s.getPrenume()<< "apartine grupei \n";
            return;
        }
    cout<<"Studentul "<<s.getNume()<<" "<<s.getPrenume()<<" nu apartine grupei ";

}
Student Grupa::getlistaStudenti(int i) const {
    return this->listaStudenti[i];
}
int Grupa::getNrStudenti() const{
    return this->nr_studenti;
}
int Grupa::getNr()  const {
    return this->nr_grupa;
}
int main() {
    /*
    Student s;
    cout << s.getNume() << endl << s.getPrenume() << endl << s.getFormafinantare() << endl<<s.getNrMatricol()<<s.getNrCredite()<<endl;
    Student s1;
    s1 = Student("Mirel"," Costin", "Buget", 1234, 789);
    Student s2(s1);
    Grupa g;
    g.setListaStudenti(1,&s1);
    cout<<g;
    cout<<g.getlistaStudenti(0)<<endl;
    Student* stud=new Student[2];
    Grupa g1=Grupa(264,2,stud);
    g1+=s1;
    cout<<g1;
    */
    //meniu interactiv
    int option;
    Grupa grup;
    Student studt;
    while(true){
        cout<<" 1. Introducere student in grupa ";
        cout<<"\n 2.Cautare daca un student se afla in grupa";
        cout<<"\n 3.Introducere datele grupei ";
        cout<<"\n 4.Afisarea datelor ";
        cout<<"\n 5.End ";
        cin>>option;
        if(option==1){
            cin>>studt;
            grup+=studt;
        }
        if(option==2){
            cin>>studt;
            grup.cautareStudent(studt);
        }
        if(option==3){
            cin>>grup;
        }
        if(option==4){
            cout<<grup<<endl;
        }
        if(option==5) {
            break;
        }
    }
    return 0;
}

