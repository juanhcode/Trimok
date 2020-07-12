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

class Ficha
{
private:
    std::string blanco;
    std::string negro;

public:
    Ficha();
    void colorFicha();
    char darFicha(int colorFicha,int posiciones, int cantidadDeFichas);
    int calcularposicion (int x, int y,int colorFicha );
    ~Ficha();
};

Ficha::Ficha(/* args */)
{
}

Ficha::~Ficha()
{
}

Ficha::Ficha Papel;
Ficha::Ficha Roca;
Ficha::Ficha Tijera;

#endif // __CLASFICHA