#pragma once
#include<iostream>
using namespace std;

/**
	DATOS

	NOMBRE_CLASE
	TIPO_N
	ATTR N
	OBJ_CLASE
	ATTR_KEY


*/

class NOMBRE_CLASE
{
	private:
		TIPO_1 ATTR_1;
		TIPO_2 ATTR_2;
		TIPO_3 ATTR_3;
		TIPO_4 ATTR_4;
		TIPO_5 ATTR_5;
		TIPO_6 ATTR_6;

	public:
		NOMBRE_CLASE();
		NOMBRE_CLASE(TIPO_1,TIPO_2,TIPO_3,TIPO_4,TIPO_5,TIPO_6);

		bool operator > (NOMBRE_CLASE&);
        bool operator < (NOMBRE_CLASE&);
        bool operator == (NOMBRE_CLASE&);
        ostream &operator << (ostream);

		void setATTR_1(TIPO_1);
		TIPO_1 getATTR_1();

		void setATTR_2(TIPO_2);
		TIPO_2 getATTR_2();

		void setATTR_3(TIPO_3);
		TIPO_3 getATTR_3();

		void setATTR_4(TIPO_4);
		TIPO_4 getATTR_4();

		void setATTR_5(TIPO_5);
		TIPO_5 getATTR_5();

		void setATTR_6(TIPO_6);
		TIPO_6 getATTR_6();


};

NOMBRE_CLASE::NOMBRE_CLASE()
{

}

NOMBRE_CLASE::NOMBRE_CLASE(TIPO_1 ATTR_1,TIPO_2 ATTR_2,TIPO_3 ATTR_3,TIPO_4 ATTR_4,TIPO_5 ATTR_5, TIPO_6 ATTR_6){
    this->ATTR_1 = ATTR_1;
    this->ATTR_2 = ATTR_2;
    this->ATTR_3 = ATTR_3;
    this->ATTR_4 = ATTR_4;
    this->ATTR_5 = ATTR_5;
    this->ATTR_6 = ATTR_6;
}


bool NOMBRE_CLASE::operator > (NOMBRE_CLASE& OBJ_CLASE){
     if (ATTR_KEY > OBJ_CLASE.ATTR_KEY)
        return true;
    return false;
}
bool NOMBRE_CLASE::operator < (NOMBRE_CLASE& OBJ_CLASE){
     if (ATTR_KEY < OBJ_CLASE.ATTR_KEY)
        return true;
    return false;
}
bool NOMBRE_CLASE::operator == (NOMBRE_CLASE& OBJ_CLASE){
     if (ATTR_KEY == OBJ_CLASE.ATTR_KEY)
        return true;
    return false;
}
ostream& NOMBRE_CLASE::operator << (ostream os){
    os << ATTR_KEY << endl;
}

void NOMBRE_CLASE::setATTR_1(TIPO_1 ATTR_1){ this->ATTR_1 = ATTR_1; }
TIPO_1 NOMBRE_CLASE::getATTR_1(){ return this->ATTR_1; }

void NOMBRE_CLASE::setATTR_2(TIPO_2 ATTR_2){ this->ATTR_2 = ATTR_2; }
TIPO_2 NOMBRE_CLASE::getATTR_2(){ return this->ATTR_2; }

void NOMBRE_CLASE::setATTR_3(TIPO_3 ATTR_3){ this->ATTR_3 = ATTR_3; }
TIPO_3 NOMBRE_CLASE::getATTR_3(){ return this->ATTR_3; }

void NOMBRE_CLASE::setATTR_4(TIPO_4 ATTR_4){ this->ATTR_4 = ATTR_4; }
TIPO_4 NOMBRE_CLASE::getATTR_4(){ return this->ATTR_4; }

void NOMBRE_CLASE::setATTR_5(TIPO_5 ATTR_5){ this->ATTR_5 = ATTR_5; }
TIPO_5 NOMBRE_CLASE::getATTR_5(){ return this->ATTR_5; }

void NOMBRE_CLASE::setATTR_6(TIPO_6 ATTR_6){ this->ATTR_6 = ATTR_6; }
TIPO_6 NOMBRE_CLASE::getATTR_6(){ return this->ATTR_6; }







