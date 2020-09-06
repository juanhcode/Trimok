/*Nombre de archivo: Tablero.h
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
Clase: Tablero
Responsabilidad:
-hay Una Ficha En Una Posicion
-es Vacia Una Posicion
-puede Moverse Ficha
-mover Ficha
-pos_Y_Primera Ficha En Aparecer
-pos_X_Primera Ficha En Aparecer
-retorno Habilitado
-puede Hacer Retorno
Colaboracion: jugador juez ficha trimok
*/
#include <vector>
#include "Ficha.h"
#include "Jugador.h"
#ifndef __CLASSTABLERO
#define __CLASSTABLERO
class Tablero
{
private:
    std::vector<std::vector<Ficha>> tablerito;
public:
    Tablero();
    ~Tablero();
    void inicializarTablero();
    void mostrarTablero();
    int verificarPosicion(int x, char y);
    bool moverFicha(string cordenadaNueva, string cordenadaActual,char colordeFicha,Jugador &jugador);
    bool retornoHabilitado(int x, int y);
    bool puedeHacerRetorno(int actualX, int actualY, int nuevaX, int nuevaY);
    bool reglas(string cordenadaNueva, string cordenadaActual,char colordeFicha,Jugador &jugador);
    bool rangoTablero();
};
#endif // __CLASTABLERO