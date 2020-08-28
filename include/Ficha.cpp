#include "Ficha.h"
#include <iostream>

Ficha::Ficha(int dColor,int dTipo,int dPosy,int dPosx){
    color = dColor,
    tipo = dTipo,
    y = dPosy,
    x = dPosx;
}

Ficha::Ficha(){
    
}

Ficha::~Ficha(){

}

int Ficha::darColor(){
    return color;   
}

int Ficha::darTipo(){
    return tipo;
}

/*string Ficha::darFicha(){
    return ficha;
}

string Ficha::setFicha(string ficha){
    this->ficha = "";
    for (int i = 0; i < ficha.length(); i++)
    {
        this->ficha +=toupper(ficha[i]);
    }
    
    this->ficha = ficha;

    return this->ficha;
}*/

int Ficha::darPosicionY(){
    return y;
}

int Ficha::darPosicionX(){
    return x;
}

bool Ficha::unEspacioVacio(){
    if (tipo = 4)
    {
        true;
    }
    else
    {
        false;
    } 
}

bool Ficha::puedeMoverse(){
    if ((color = 0) and (tipo=0))
    {
        true;
    }
    else
    {
        false;
    }
}

int Ficha::puedeComerUnaFicha(Ficha fichaAComer){

}

int Ficha::retornoHabilitado(){

}

void Ficha::cambiarTipo(int nuevoTipo){
    tipo = nuevoTipo;
}