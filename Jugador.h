/*Nombre de archivo: Jugador.h
Version: 0.1
Fecha de creacion: 29/06/2020
Fecha de ultima de moficacion: 29/06/2020
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
/*CRC:
Clase: Jugador
Responsabilidad:
-Mostrar el dia de la fecha.
-Mostrar el mes de la fecha.
-Mostrar el anio de la fecha.
-Calcular una diferencia entre meses de la fecha.
Colaboracion: Ninguna.
*/
#ifndef __CLASSJUGADOR
#define __CLASSJUGADOR
#include "Ficha.h"
class Jugador{
    private:

    public:

    Jugador(){
    }
    
    int moverficha(Ficha);
    void obtenerFicha(Ficha);
    void capturarFichasDelOpositor();
    void asignarFicha(Ficha);


};


Jugador::Jugador_blanco();
Jugador::Jugador_Negro();

#endif // __CLASJUGADOR