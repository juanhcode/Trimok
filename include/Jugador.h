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
-capturar fichas del opositor
-movimiento especial
-seleccionar ficha posicion
-agregar dicha posicion 
-agregar ficha 
Colaboracion:tablero
*/
#include "Ficha.h"
#include "Tablero.h"
#ifndef __CLASSJUGADOR
#define __CLASSJUGADOR
class Jugador
{
private:

public:
    Jugador();
    int moverFicha(Ficha FichaN,Ficha FichaB,int posicion);
    int capturarFichasDelOpositor(Ficha FichaN,Ficha FichaB,Tablero Tablerito);
    int movimientoEspecial(Ficha,Tablero Tablerito);
    bool seleccionar(Ficha FichaN,Ficha FichaB, int Posicion);
    bool agregarFicha(Ficha FichaN,Ficha FichaB,int posicion);
    ~Jugador();
};
#endif // __CLASJUGADOR