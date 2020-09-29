#include "Ficha.h"
#include <iostream>

Ficha::Ficha(int dColor, string dTipo, int dPosy, int dPosx)
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

string Ficha::darTipo()
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
    
}

bool Ficha::fichaExiste(string posicion)
{
    bool posX = false;
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
    }

    if ((posX == true) and (posY == true))
    {
        return true;
    }
    else
    {
        return false;
    }
  
    
}

bool Ficha::puedeMoverse()
{
}

int Ficha::puedeComerUnaFicha(Ficha fichaAComer)
{
}

int Ficha::retornoHabilitado()
{
}

void Ficha::cambiarTipo(string nuevoTipo)
{
    tipo = nuevoTipo;
}