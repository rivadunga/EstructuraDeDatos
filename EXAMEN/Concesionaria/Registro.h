#pragma once
#include<iostream>
#include "Vehiculo.h"
#include "Comprador.h"

using namespace std;

/**
	DATOS

	Registro
	TIPO_N
	ATTR N
	registro
	monto


*/

class Registro
{
	private:
		float monto;
		Vehiculo* vehiculo;
		Comprador comprador;

	public:
		Registro();
		Registro(float monto,Vehiculo*,Comprador);

		bool operator > (Registro&);
        bool operator < (Registro&);
        bool operator == (Registro&);
        ostream &operator << (ostream);

		void setmonto(float);
		float getmonto();

		void setvehiculo(Vehiculo*);
		Vehiculo* getvehiculo();

		void setcomprador(Comprador);
		Comprador getcomprador();



};

Registro::Registro()
{

}

Registro::Registro(float monto,Vehiculo* vehiculo,Comprador comprador){
    this->monto = monto;
    this->vehiculo = vehiculo;
    this->comprador = comprador;
}


bool Registro::operator > (Registro& registro){
     if (monto > registro.monto)
        return true;
    return false;
}
bool Registro::operator < (Registro& registro){
     if (monto < registro.monto)
        return true;
    return false;
}
bool Registro::operator == (Registro& registro){
     if (monto == registro.monto)
        return true;
    return false;
}
ostream& Registro::operator << (ostream os){
    os << monto << endl;
}

void Registro::setmonto(float monto){ this->monto = monto; }
float Registro::getmonto(){ return this->monto; }

void Registro::setvehiculo(Vehiculo* vehiculo){ this->vehiculo = vehiculo; }
Vehiculo* Registro::getvehiculo(){ return this->vehiculo; }

void Registro::setcomprador(Comprador comprador){ this->comprador = comprador; }
Comprador Registro::getcomprador(){ return this->comprador; }









