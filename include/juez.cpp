#include "juez.h"

Juez::Juez()
{
    puntajeJugador1 = 0;
    //puntajeJugador2 = 0;
}

Juez::~Juez()
{
}

string Juez::mostrarGanador(int puntajeFichaNegra, int puntajeFichaBlanca)
{
}

int Juez::darPuntajeJugador1()
{
    return puntajeJugador1;
}

void Juez::setPuntajeJugador1(int nuevoPuntajeJug1)
{
    puntajeJugador1 += nuevoPuntajeJug1;
}

/*int Juez::darPuntajeJugador2()
{
    return puntajeJugador2;
}

void Juez::setPuntajeJugador2(int nuevoPuntajeJug2)
{
    puntajeJugador2 += nuevoPuntajeJug2;
}*/