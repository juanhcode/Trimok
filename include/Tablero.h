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
class Tablero
{
private:
    std::vector<std::vector<Ficha>>tablerito;
public:
    Tablero();
    void mostrarTablero();
    bool hayUnaFichaEnUnaPosicion(int x, int y);
    bool esVaciaUnaPosicion(int x, int y);
    bool puedeMoverseFicha(int x, int y);
    void moverFicha(int actualX, int actualY, int nuevaX, int nuevaY);
    int pos_Y_PrimeraFichaEnAparecer(int color);
    int pos_X_PrimeraFichaEnAparecer(int color);
    Ficha darFicha(int x,int y);
    bool retornoHabilitado(int x, int y);
    bool puedeHacerRetorno(int actualX, int actualY, int nuevaX, int nuevaY);
    ~Tablero();
};