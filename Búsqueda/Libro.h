#include<iostream>
#include<string>
using namespace std;

class Libro
{
    public:
        string _titulo;
        int _anio;
        string _isbn;

    public:
        Libro();
        Libro(string,int,string);
        bool operator==(Libro &);
        bool operator<(Libro &);
        ostream &operator << (ostream);
};

Libro::Libro()
{

}

Libro::Libro(string titulo, int anio, string isbn)
{
    _titulo = titulo;
    _anio   = anio;
    _isbn   = isbn;
}

bool Libro::operator==(Libro & libro)
{
    if (libro._isbn == _isbn)
        return true;
    return false;
}

bool Libro::operator <(Libro & libro)
{
    if (_isbn < libro._isbn)
        return true;
    return false;
}

ostream& Libro::operator << (ostream os)
{
    os << _titulo << endl;
}





