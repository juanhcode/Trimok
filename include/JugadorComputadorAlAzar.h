/*Nombre de archivo: Ficha.h
Version: 0.1
Fecha de creacion: 29/06/2020
Fecha de ultima de moficacion: 29/06/2020
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
Clase: JugadorComputadorAlAzar
Responsabilidad:
-mover ficha aleatoriamente 
-movimiento especial
Colaboracion: Jugador
*/
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
    void cambiarNick(string nuevoNick);
    void setPuntaje(int nuevoPuntaje);
    void poderRetornar(char color, int puntaje);
};
#endif // __CLASJUGADORCOMPUTADORALAZAR