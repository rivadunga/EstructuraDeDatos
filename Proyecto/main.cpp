#include<iostream>
#include<vector>
#include<string>
#include <stdlib.h>
#include "Entrada.h"
#include "Grafo.h"
#include "Tuit.h"
#include "Persona.h"
using namespace std;



Grafo<Persona> tuiter;
Persona* user;
Persona* perfil;
Entrada entrada;

void iniciarDatosPrueba();

int main()
{
    iniciarDatosPrueba();

    while (true)
    {

    cout << "\nBienvenido a tuiter" << endl;

    string nombre;
    do{
    cout << "\nUsuario: ";
    }while (!entrada.cadena(nombre));

    system("cls");
    if (tuiter.searchByName("@" + nombre) == nullptr){
        user = new Persona("@" + nombre);
        tuiter.registrar(user);
        cout << "\nBienvenido" << endl;
    }
    else{
        user = tuiter.searchByName("@" + nombre);
        cout << "\nHola de nuevo :)" << endl;

    }

    perfil = user;

    while (true){

        vector<Persona*> followers = tuiter.getFollowers(perfil);
                        vector<Persona*> follow = tuiter.getFollowed(perfil);
        vector<Tuit*> tuits = perfil->getTuits();


        if (*perfil == *user){
            cout << "\n ::: " << perfil->getNombre() << " ::: Yo\n\n";
            cout << "  [1] Tuits         x" << tuits.size() << "\n  [2] Followers     x" << followers.size() << "\n  [3] Following     x" << follow.size() << "\n  [4] Buscar\n  [5] Thrending topics \n  [6] Salir\n";
        }
        else{
            cout << "\n Perfil de " << perfil->getNombre() << "\n\n";
            string followMenuStr = "Follow";
            if (tuiter.isFollower(user,perfil)) followMenuStr = "Unfollow";
            cout << "  [1] Tuits         x" << tuits.size() << "\n  [2] Followers     x" << followers.size() << "\n  [3] Following     x" << follow.size() << "\n  [4] "+followMenuStr+"\n  [5] Regresar\n";
        }
        int opc;
        cout << "\n";
        do{
            cout << "Selecciona una opcion: ";
        }while (!entrada.entero(opc,1,6));
        system("cls");




        if (opc == 1){
            cout << "\nTuits\n\n";
            for (int i = 0; i < tuits.size(); i++){
                cout << "  ";
                if (!(*perfil == *user))
                    cout << "["<<i+1<<"] ";
                cout << tuits[i]->getUsuario()->getNombre() << " " << tuits[i]->getContenido() << endl;
            }
            cout << "\n\n";
            int opc;
             if (*perfil == *user){
                cout << "[1] Nuevo tuit\n[2] Regresar\n\n";
                int opc2 = 0;
                do{
                    cout << "Selecciona una opcion: ";
                }while (!entrada.entero(opc2,1,2));

                if (opc2 == 1){
                    string tuitStr;
                    cout << "\n\n";
                    do{
                        cout << "    Tuit: ";
                    }while (!entrada.cadena(tuitStr));

                    if (tuitStr.length() > 117)
                    {
                        cout << "No puedes poner mas de 117 caracteres\n";
                        entrada.cualquierTecla();
                    }else{
                        perfil->nuevoTuit(tuitStr);
                    }

                }
             }else{
                cout << "[n] Retuitear\n[0] Regresar\n\n";
                int opc2 = 0;
                do{
                    cout << "Selecciona una opcion: ";
                }while (!entrada.entero(opc2,0,tuits.size()));

                if (opc2 != 0){
                    user->nuevoTuit(tuits.at(opc2-1));
                    cout << "Tuit retuiteado";
                    entrada.cualquierTecla();
                }
             }
        }





        if (opc == 2)
        {
            cout << "\nFollowers\n\n";
            for (int i = 0; i < followers.size(); i++)
                cout << "  ["<<i+1<<"]" << followers[i]->getNombre() << endl;

            cout << "\n\n[n] Ir a perfil\n[0] Regresar\n\n";
            int opc2 = 0;
            do{
                cout << "Selecciona una opcion: ";
            }while (!entrada.entero(opc2,0,followers.size()));

            if (opc2 != 0){
                if (tuiter.searchByName(followers[opc2-1]->getNombre()) != nullptr){
                    perfil = tuiter.searchByName(followers[opc2-1]->getNombre());
                }
            }
        }




        if (opc == 3)
        {
            cout << "\nFollowing\n\n";
            for (int i = 0; i < follow.size(); i++)
                cout << "  ["<<i+1<<"]" <<  follow[i]->getNombre() << endl;
             cout << "\n\n[n] Ir a perfil\n[0] Regresar\n\n";
            int opc2 = 0;
            do{
                cout << "Selecciona una opcion: ";
            }while (!entrada.entero(opc2,0,follow.size()));

            if (opc2 != 0){
                if (tuiter.searchByName(follow[opc2-1]->getNombre()) != nullptr){
                    perfil = tuiter.searchByName(follow[opc2-1]->getNombre());
                }
            }
        }




        if (opc == 4)
        {
            if (*user == *perfil)
            {
                cout << "\nBuscar\n\n";
                string buscado;
                do{
                    cout << "User: ";
                }while (!entrada.cadena(buscado));

                if (tuiter.searchByName(buscado) != nullptr){
                    perfil = tuiter.searchByName(buscado);
                }else{
                    if (tuiter.searchByName("@" + buscado) != nullptr){
                        perfil = tuiter.searchByName("@"+buscado);
                    }else{
                        cout << "\nNo se encuentra\n";
                        entrada.cualquierTecla();
                    }
                }
            }else{
                if (!tuiter.isFollower(user,perfil))
                {
                    tuiter.follow(user,perfil);
                    cout << "\nAhora sigues a " << perfil->getNombre() << "\n";
                    entrada.cualquierTecla();
                }else{
                    tuiter.unFollow(user,perfil);
                    cout << "\nYa no sigues a " << perfil->getNombre() << " :( \n";
                    entrada.cualquierTecla();
                }
                perfil = user;
            }
        }




        if (opc == 5){
            if (*user == *perfil){
                cout << "\nTrending topics\n\n";
                vector<string> tt = tuiter.trendingTopics();
                for (int i = 0; i < tt.size(); i++)
                    cout << "  [" << i+1 << "] " << tt[i] << endl;


                cout << "\n\n[n] Ver tuits\n[0] Regresar\n\n";
                int opc2 = 0;
                do{
                    cout << "Selecciona una opcion: ";
                }while (!entrada.entero(opc2,0,tt.size()));

                if (opc2 != 0){
                    system("cls");
                    cout << "\nTuits de " + tt[opc2-1] + "\n\n";
                    vector<Tuit> tuitsTT = tuiter.getTuitsTrendingTopic(tt[opc2-1]);
                    for (int i = 0; i < tuitsTT.size(); i++){
                        cout << " " << tuitsTT[i].getUsuario()->getNombre() << " " << tuitsTT[i].getContenido() << endl;
                    }
                    entrada.cualquierTecla();
                }

            }else{
                perfil = user;
            }
        }

        if (opc == 6){
            if (*user == *perfil){
                break;
            }
        }

        system("cls");

    }

    }

    return 0;

}



void iniciarDatosPrueba()
{
    Persona* persona1 = new Persona("@Erick");
    Persona* persona2 = new Persona("@Ponchito");
    Persona* persona3 = new Persona("@Juan");
    Persona* persona4 = new Persona("@John");
    Persona* persona5 = new Persona("@Maria");
    tuiter.registrar(persona1);
    tuiter.registrar(persona2);
    tuiter.registrar(persona3);
    tuiter.registrar(persona4);
    tuiter.registrar(persona5);
    tuiter.follow(persona1,persona2);
    tuiter.follow(persona1,persona4);
    tuiter.follow(persona3,persona1);
    tuiter.follow(persona2,persona4);
    tuiter.follow(persona2,persona3);

    persona1->nuevoTuit("Buenos dias");
    persona1->nuevoTuit("Como estan todos");
    persona1->nuevoTuit("#YOLO");
    persona1->nuevoTuit("Blaham blaham");
    persona1->nuevoTuit("jajaja ");

    persona2->nuevoTuit("Cruz azul fail");
    persona2->nuevoTuit("UNAM rules");
    persona2->nuevoTuit("Esak");
    persona2->nuevoTuit("kl salk dsa");

    persona3->nuevoTuit("Hola erick #QueNoTruene");
    persona3->nuevoTuit("Espero que todo este bien #blaham");
    persona3->nuevoTuit("Hola #SiYaTronoYaNiModo");


}
