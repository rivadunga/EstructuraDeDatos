#include<iostream>
#include<string.h>
#include <fstream>
#include <cstdlib>
#include"Node.h"
#include"DobleCircularLinkedList.h"


using namespace std;
using namespace vcn;



void cargarArchivo(DobleCircularLinkedList<char>*&);
void guardarArchivo(DobleCircularLinkedList<char>*);
int getCursorLinea(int,DobleCircularLinkedList<char>*);
void imprimirArchivo(int,DobleCircularLinkedList<char>*);
void imprimirComandos();



int main()
{
    DobleCircularLinkedList<char>* archivo = new DobleCircularLinkedList<char>;

    cout << "Bienvenido a ErickWord" << endl << endl;
    int opc;
    cout << "Nuevo archivo [1], cargar archivo [2]: ";
    cin >> opc;
    if (opc == 2)
        cargarArchivo(archivo);


    imprimirComandos();


    bool redactando = true;
    int cursor = archivo->size();

    while (true)
    {

        system("cls");
        imprimirArchivo(cursor,archivo);
        string line = "";

        if (redactando){
            cout << " > ";
            getline (cin,line);
        }


        if (line != "" || !redactando){

            if (redactando){
                for (int i = 0; i < line.length(); i++){
                     archivo->LinkedList::insert(line.at(i),cursor);
                     cursor++;
                }

            }


            system("cls");
            imprimirArchivo(cursor,archivo);

            string comando;
            cout << endl;
            cout << " <> Comando (n,b,i,f,g,s,help): ";
            cin >> comando;

            if (comando == "n"){
                archivo->LinkedList::insert('\n',cursor);
                cursor++;
                redactando = true;
            }

            if (comando == "b"){
                cursor--;
                archivo->LinkedList::remove(cursor);
                redactando = false;
            }

            if (comando == "i"){
                int numLinea;
                cout << "Ir al inicio de la linea #: ";
                cin >> numLinea;
                cursor = getCursorLinea(numLinea,archivo);
                redactando = false;
            }

            if (comando == "f"){
                int numLinea;
                cout << "Ir al final de la linea #: ";
                cin >> numLinea;
                if (cursor >= archivo->size())
                    cursor = getCursorLinea(numLinea+1,archivo);
                else
                    cursor = getCursorLinea(numLinea+1,archivo)-1;
                redactando = false;
            }



            if (comando == "help") {
                imprimirComandos();
                redactando = false;
            }

            if (comando == "g"){
                guardarArchivo(archivo);
                cout << "Archivo guardado en \"archivo.txt\"" << endl;
                break;
            }

            if (comando == "s") {
                break;
            }
        }
    }
}





void cargarArchivo(DobleCircularLinkedList<char> *& f)
{
  ifstream txt ("archivo.txt");
  if (txt.is_open())
  {
    string line;
    while (getline (txt,line)){
        for (int i = 0; i < line.length(); i++)
            f->insertBack(line.at(i));
        f->insertBack('\n');
    }

    cout << "Archivo cargado" << endl;
    txt.close();
  }
  else
    cout << "No existe archivo" << endl;


}

void guardarArchivo(DobleCircularLinkedList<char>* f)
{
    ofstream txt;
    txt.open ("archivo.txt");
    for (int i = 0; i < f->size(); i++){
        txt << f->at(i)->getInfo();
    }
}

int getCursorLinea(int numLinea,DobleCircularLinkedList<char>* f){
    int lineaAct = 1;
    int pos = 0;
    while (pos < f->size() && lineaAct != numLinea){
        if (f->at(pos)->getInfo() == '\n'){
            lineaAct++;
        }
        pos++;
    }
    return pos;
}

void imprimirArchivo(int cursor, DobleCircularLinkedList<char>* f)
{
     for (int i = 0; i < f->size(); i++){
        if (i == cursor)
            cout << "#";
        cout << f->at(i)->getInfo();
    }
    if (cursor == f->size())
        cout << "#\n";
}

void imprimirComandos()
{
    cout << endl;
    cout << " Comandos" << endl;
    cout << "   [n] Nueva linea " << endl;
    cout << "   [b] Borrar letra " << endl;
    cout << "   [i] Ir a inicio de linea " << endl;
    cout << "   [f] Ir a final de linea " << endl;
    cout << "   [g] Guardar " << endl;
    cout << "   [s] Salir " << endl << endl;

    char aux;
    cout << "Presiona cualquier tecla para iniciar: ";
    cin >> aux;
}

