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
    
}

int Ficha::puedeComerUnaFicha(Ficha fichaAComer){

}

int Ficha::retornoHabilitado(){

}

void Ficha::cambiarTipo(int nuevoTipo){
    tipo = nuevoTipo;
}