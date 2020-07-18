#include "Ficha.h"
#include <iostream> 
#include <vector>
class Tablero
{
private:
    vector<Ficha> Tablerito;
public:
    Tablero();
    bool hayUnaFichaEnUnaPosicion(int x, int y);
    bool esVaciaUnaPosicion(int x, int y);
    bool puedeMoverseFicha(int x, int y);
    void moverFicha(int actualX, int actualY, int nuevaX, int nuevaY);
    int pos_Y_PrimeraFichaEnAparecer(int color);
    int pos_X_PrimeraFichaEnAparecer(int color);
    bool retornoHabilitado(int x, int y);
    bool puedeHacerRetorno(int actualX, int actualY, int nuevaX, int nuevaY);
    ~Tablero();
};

Tablero::Tablero(/* args */)
{
}

Tablero::~Tablero()
{
}
