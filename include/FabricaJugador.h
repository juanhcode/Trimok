/*Nombre de archivo: FabricaJugador.h
Version: 0.1
Fecha de creacion: 29/06/2020
Fecha de ultima de moficacion: 15/09/2020
Autor: Juan Manuel Hoyos Contreras - 201958950-2711
     : Luis alberto alegria riascos -201958640-2711
     : Emanuel benjumea bejarano - 201958941-2711
     : cesar augusto gallego niño 1958553-2711
     : Steven Vargas González 1958675-2711
Correos electronicos: juan.manuel.hoyos@correounivalle.edu.co
                    : vargas.steven@correounivalle.edu.co
                    : Emanuel.benjumea@correounivalle.edu.co
                    : gallego.cesar@correounivalle.edu.co
                    : Lui.alegria@correounivalle.edu.co
/*CRC:
Clase: FabricaJugador
Responsabilidad:  crea dinámicamente los objetos correspondientes
Colaboracion: Jugador
*/
#ifndef __CLASSFABRICAJUGADOR
#define __CLASSFABRICAJUGADOR
#include "JugadorComputadorAlAzar.h"
#include "JugadorHumano.h"
class FabricaJugador
{
private:
    
public:
    FabricaJugador();
    JugadorComputadorAlAzar* darMaquina();
    JugadorHumano* darHumano();
    void modo1(JugadorHumano *jugadorBlanco,JugadorHumano *jugadorNegro);
    ~FabricaJugador();
};

#endif // __CLASFABRICAJUGADOR