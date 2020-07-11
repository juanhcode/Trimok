#include "Ficha.h"
class Tablero
{
private:
    int x;
    int y;
    int puntaje;
public:
    Tablero();
    void mostrarFichas(Ficha);
    int cambiarPuntaje(int puntaje);
    ~Tablero();
};

Tablero::Tablero(/* args */)
{
}

Tablero::~Tablero()
{
}
