/*Nombre de archivo: Ficha.h
Version: 0.1
Fecha de creacion: 29/06/2020
Fecha de ultima de moficacion: 11/07/2020
Autor: Juan Manuel Hoyos Contreras - 201958950-2711
     : Luis alberto alegria riascos -201958640-2711
     : Emanuel benjumea bejarano - 201958941-2711
     : Yilber Alexander viscue- 201968070-2711
     : cesar augusto gallego niño 1958553-2711
     : Steven Vargas González 1958675-2711
Correos electronicos: juan.manuel.hoyos@correounivalle.edu.co
                    : vargas.steven@correounivalle.edu.co
                    : Emanuel.benjumea@correounivalle.edu.co
                    : yilber.viscue@correounivalle.edu.co
                    : gallego.cesar@correounivalle.edu.co
                    : Lui.alegria@correounivalle.edu.co
/CRC:
Clase: tablero 
Responsabilidad: 
-mostrar ficha
-cambiar Puntaje
Colaboracion: Ficha
*/
#ifndef __CLASSTABLERO
#define __CLASSTABLERO
#include "Ficha.h"
class Tablero
{
private:
public:
    Tablero();
    bool hayUnaFichaEnUnaPosicion(int x,int y);
    bool esVaciaUnaPosicion(int x,int y);
    bool puedeMoverFicha(int posx,int posy);
    void moverFicha(int actualx,int actualy,int nuevax,int nuevay);
    int posYPrimeraFichaEnAaparecer(int color);
    int posXPrimeraFichaEnAaparecer(int color);
    Ficha darFicha(int x, int y);
    bool retornoHabilitado(int x,int y);
    bool puedeHacerRetorno(int actualx,int actualy,int nuevax,int nuevay);
    ~Tablero();
};

#endif // __CLASTABLERO

