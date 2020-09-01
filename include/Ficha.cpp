#include "Ficha.h"
#include <iostream>

Ficha::Ficha(int dColor, int dTipo, int dPosy, int dPosx)
{
    color = dColor,
    tipo = dTipo,
    y = dPosy,
    x = dPosx;
}

Ficha::Ficha()
{
}

Ficha::~Ficha()
{
}

int Ficha::darColor()
{
    return color;
}

int Ficha::darTipo()
{
    return tipo;
}

int Ficha::darPosicionY()
{
    return y;
}

int Ficha::darPosicionX()
{
    return x;
}

bool Ficha::unEspacioVacio()
{
    if (tipo = 4)
    {
        true;
    }
    else
    {
        false;
    }
}

bool Ficha::fichaExiste(string posicion)
{
    /*bool posX = false;
    bool posY = false;
    string x = "ABCDEF";
    string y = "123456";

    for (int i = 0; i < 6; i++)
    {
        if (posicion[0] == x[i])
        {
            posX = true;
        }
        if (posicion[1] == y[i])
        {
            posY = true;
        }
    }*/

    /*if ((posX == true) and (posY == true))
    {
        return true;
    }
    else
    {
        return false;
    }*/
  
    
}

bool Ficha::puedeMoverse()
{
    if ((color = 0) and (tipo = 0))
    {
        true;
    }
    else
    {
        false;
    }
}

int Ficha::puedeComerUnaFicha(Ficha fichaAComer)
{
}

int Ficha::retornoHabilitado()
{
}

void Ficha::cambiarTipo(int nuevoTipo)
{
    tipo = nuevoTipo;
}