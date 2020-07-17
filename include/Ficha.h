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
Clase: Ficha
Responsabilidad:
-color de la Ficha
- dar ficha
-Calcular posicion 
Colaboracion: Tablero
*/
#ifndef __CLASSFICHA
#define __CLASSFICHA
#include <iostream>
using namespace std;

class Ficha
{
private:
    int color;//
    int tipo;
    int X;
    int Y;

public:
    Ficha(int color,int tipo,int posicionEnX,int posicionEnY);
    int darColor();
    int darTipo();
    int darPosicionEnX();
    int darPosicionEnY();
    bool esUnEspacioVacio();
    bool puedeMoverse();
    bool puedeComerUnaFicha(Ficha fichaAComer);
    bool retornoHabilitado();
    void cambiarTipo(int nuevoTipo);
    ~Ficha();
};

#endif // __CLASFICHA