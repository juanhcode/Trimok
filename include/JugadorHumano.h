#include "Jugador.h"
#ifndef __CLASSJUGADORHUMANO
#define __CLASSJUGADORHUMANO
class JugadorHumano : public Jugador
{
private:
    /* data */
public:
    JugadorHumano();
    bool moverFicha(string cordenadaNueva, string cordenadaActual, char colordeFicha);
    bool reglas(string cordenadaNueva, string cordenadaActual, char colordeFicha);
    string darNick();
    int darPuntaje();
    string cambiarNick(string nuevoNick);
    void setPuntaje(int nuevoPuntaje);
    //void mostrarDatos();
    ~JugadorHumano();
};

#endif // __CLASJUGADORHUMANO
