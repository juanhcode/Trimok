#include "Ficha.h"
class Jugador
{
private:
    /* data */
public:
    Jugador(/* args */);
    int moverFicha();
    int capturarFichasDelOpositor();
    int movimientoEspecial(int cantidadDeFichas);
    bool seleccionarFichaPosicion(int Ficha, int Posicion);
    bool agregarFicha(int Ficha);
   

    ~Jugador();
};

Jugador::Jugador(/* args */)
{
}

Jugador::~Jugador()
{
}
