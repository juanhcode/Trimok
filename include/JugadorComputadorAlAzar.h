#include "Jugador.h"
#ifndef __CLASSJUGADORCOMPUTADORALAZAR
#define __CLASSJUGADORCOMPUTADORALAZAR
class JugadorComputadorAlAzar : public Jugador
{
private:

public:
    JugadorComputadorAlAzar();
    ~JugadorComputadorAlAzar();
    bool moverFicha(string cordenadaNueva, string cordenadaActual, char colordeFicha);
    bool reglas(string cordenadaNueva, string cordenadaActual, char colordeFicha);
    string darNick();
    int darPuntaje();
    string cambiarNick(string nuevoNick);
    void setPuntaje(int nuevoPuntaje);
    
};
#endif // __CLASJUGADORCOMPUTADORALAZAR