/*Nombre de archivo: Jugador.h
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
Clase: Jugador
Responsabilidad:
-mover ficha
-movimiento especial
-poder Retornar
Colaboracion:tablero
*/
#include "Ficha.h"
#include "Tablero.h"
#include "juez.h"
#ifndef __CLASSJUGADOR
#define __CLASSJUGADOR
class Jugador
{
private:
protected:
    string nick;
    int puntaje;
    Tablero tablero;
    int posX;
    int posY;
    int posxNueva;
    int posyNueva;
    Juez juez;

public:
    Jugador();
    virtual int darPuntaje() = 0;
    virtual void setPuntaje(int nuevoPuntaje) = 0;
    virtual string darNick() = 0;
    virtual void cambiarNick(string nuevoNick) = 0;
    virtual bool moverFicha(string cordenadaNueva, string cordenadaActual, char colordeFicha) = 0;
    virtual bool reglas(string cordenadaNueva, string cordenadaActual, char colordeFicha) = 0;
    virtual void poderRetornar(char color,int puntaje) = 0;
    ~Jugador();
};
#endif // __CLASJUGADOR