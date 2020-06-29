#include "Ficha.h"
class Jugador{
    private:

    public:

    Jugador(){
    }
    
    int moverficha(Ficha);
    void obtenerFicha(Ficha);
    void capturarFichasDelOpositor();
    void asignarFicha(Ficha);


};


Jugador::Jugador blanco();
Jugador::Jugador Negro();