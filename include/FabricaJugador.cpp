#include "FabricaJugador.h"

FabricaJugador::FabricaJugador()
{
}

FabricaJugador::~FabricaJugador()
{
}
//se crea dinámicamente los objetos correspondientes
JugadorComputadorAlAzar *FabricaJugador::darMaquina()
{
    return new JugadorComputadorAlAzar();
}

JugadorHumano *FabricaJugador::darHumano()
{
    return new JugadorHumano();
}

void FabricaJugador::modo1(JugadorHumano *jugadorBlanco, JugadorHumano *jugadorNegro)
{
    jugadorBlanco = new JugadorHumano();
    jugadorNegro = new JugadorHumano();
}