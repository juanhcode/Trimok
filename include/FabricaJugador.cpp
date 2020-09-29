#include "FabricaJugador.h"

FabricaJugador::FabricaJugador()
{
}

FabricaJugador::~FabricaJugador()
{
}

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

/*void FabricaJugador::pareja2(JugadorComputadorAlAzar *jugadorMaquina,)
{
    jugadorMaquina = new JugadorComputadorAlAzar();
    jugadorNegroPareja2 = new JugadorHumano();
}

void FabricaJugador::pareja3(JugadorComputadorAlAzar &jugadorMaquinaB, JugadorComputadorAlAzar &jugadorMaquinaN)
{
    jugadorMaquinaB = *(new JugadorComputadorAlAzar());
    jugadorMaquinaN = *(new JugadorComputadorAlAzar());

}
void FabricaJugador::pareja4(JugadorHumano &jugadorBlanco, JugadorHumano &jugadorNegro)
{
    jugadorBlanco = *(new JugadorHumano());

    jugadorNegro = *(new JugadorHumano());
}*/
