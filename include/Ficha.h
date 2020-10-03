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
Clase: Ficha
Responsabilidad:
-dar el tipo de la ficha
-dar posicion Y
-dar dar Posicion X
-dar unEspacioVacio 
-puede moverse
-puede comer una ficha
-retorno habilitado
-cambiar tipo
Colaboracion: tablero
*/
#ifndef __CLASSFICHA
#define __CLASSFICHA
using namespace std;
#include <string>

class Ficha
{
private:
    int color;   // 1 = blanco, 2 = negro, 3 = vacio
    string tipo; // R = ROCA, P = Papel, T = Tijera, "V" = vacio
    int x;
    int y;

public:
    Ficha();
    Ficha(int dColor, string dTipo, int dPosy, int dPosx);
    int darColor();
    string darTipo();
    int darPosicionY();
    int darPosicionX();
    void cambiarTipo(string nuevoTipo);
    bool fichaExiste(string posicion);
    ~Ficha();
};
#endif // __CLASFICHA