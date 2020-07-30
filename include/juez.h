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
Clase: Juez
Responsabilidad:
-mostrar ganador
Colaboracion: tablero
*/
#ifndef __CLASSJUEZ
#define __CLASSJUEZ
#include <iostream>
using namespace std;
class Juez
{
private:
    
public:
    Juez();
    string mostrarGanador(int puntajeFichaNegra, int puntajeFichaBlanca);
    ~Juez();
};
#endif // __CLASJUEZ

