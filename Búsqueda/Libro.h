#include<string>
using namespace std;

class Libro{
    public:
        string titulo;
        int anio_pub;
        string isbn;

    public:
        Libro();
        Libro(string,int,string);
        friend ostream & operator << (ostream,Libro);
}

Libro::Libro()
{

}

Libro::Libro(string a, int b, string c)
{

}

ostream & operator << (ostream os, Libro libro)
{
    os << libro.titulo;
}





