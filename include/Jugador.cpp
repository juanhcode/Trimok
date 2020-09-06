#include "Jugador.h"
Jugador::Jugador(){
    puntaje = 0;
}

Jugador::~Jugador(){

}

string Jugador::darNick(){
    return nick;
}

string Jugador::cambiarNick(string nuevoNick){
    nick = nuevoNick;
}

int Jugador::darPuntaje(){
    return puntaje;
}
void Jugador::setPuntaje(int nuevoPuntaje){
    puntaje += nuevoPuntaje;
}

bool Jugador::seleccionar(Ficha FichaN,Ficha FichaB, int Posicion){

}

bool Jugador::agregarFicha(Ficha FichaN,Ficha FichaB,int posicion){

}
