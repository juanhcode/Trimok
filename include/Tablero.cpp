#include "Tablero.h"
#include <iostream>
#include <vector>
using namespace std;

Tablero::Tablero()
{
}

Tablero::~Tablero()
{
}

void Tablero::inicializarTablero()
{
    tablerito.clear(); //Limpiar
    for (int i = 0; i < 6; i++)
    {
        vector<Ficha> fichaActual; //Auxiliar
        for (int j = 0; j < 6; j++)
        {
            if (i == 0 or i == 1)
            {
                if (j == 0 or j == 3)
                {
                    Ficha tijeraN(2, 3, 0, 0);
                    fichaActual.push_back(tijeraN);
                }
                else if (j == 1 or j == 4)
                {
                    Ficha papelN(2, 2, 0, 0);
                    fichaActual.push_back(papelN);
                }
                else if (j == 2 or j == 5)
                {
                    Ficha RocaN(2, 1, 0, 0);
                    fichaActual.push_back(RocaN);
                }
            }
            else if (i == 4 or i == 5)
            {
                if (j == 0 or j == 3)
                {
                    Ficha tijeraB(1, 3, 0, 0);
                    fichaActual.push_back(tijeraB);
                }
                else if (j == 1 or j == 4)
                {
                    Ficha papelB(1, 2, 0, 0);
                    fichaActual.push_back(papelB);
                }
                else if (j == 2 or j == 5)
                {
                    Ficha RocaB(1, 1, 0, 0);
                    fichaActual.push_back(RocaB);
                }
            }
            else
            {
                Ficha vacia(3, 4, 0, 0);
                fichaActual.push_back(vacia);
            }
        }
        tablerito.push_back(fichaActual);
    }
}

void Tablero::mostrarTablero()
{
    string mensaje;
    for (int i = 0; i < tablerito.size(); i++)
    {
        for (int j = 0; j < tablerito.size(); j++)
        {
            if (tablerito[i][j].darColor() == 1)
            {
                mensaje = "B";
            }
            else if (tablerito[i][j].darColor() == 2)
            {
                mensaje = "N";
            }
            else
            {
                mensaje = "V";
            }
            cout << mensaje << tablerito[i][j].darTipo() << " | ";
        }
        cout << endl;
    }
}

bool Tablero::hayUnaFichaEnUnaPosicion(int x, int y)
{
    //si la casilla es igual a B V o N entonces la posicion esta ocupada en la posicion x y
    
}

bool Tablero::esVaciaUnaPosicion(int x, int y)
{
    // si la casilla esta ocupada es false si no es true

}

bool Tablero::puedeMoverseFicha(int x, int y)
{
    //si se cumple con las condiciones se puede mover la ficha
}

void Tablero::moverFicha(int actualX, int actualY, int nuevaX, int nuevaY)
{
    nuevaX = actualX;
    nuevaY = actualY;

    bool bMovidaPosible = false;
}

int Tablero::pos_Y_PrimeraFichaEnAparecer(int color)
{
    //ingresa la primera ficha en la pocion y
}

int Tablero::pos_X_PrimeraFichaEnAparecer(int color)
{
}

Ficha Tablero::darFicha(int x, int y)
{
}

bool Tablero::retornoHabilitado(int x, int y)
{
    //si Bb , Nb o Vb ocupan i = 6 true si no false.
}

bool Tablero::puedeHacerRetorno(int actualx, int actualy, int nuevax, int nuevay)
{
    /*para hacer el retorno se nesecita mirar si la ficha que llega esta sola en su fila correspondiente
    en ese caso se podra hacer y el retorno */

    int i = 0;
    int j = 0;
    if (nuevax)
    {
        if (nuevay)
        {
            tablerito[i][j];
            i++;
            j++;
            Tablero::darFicha;
        }
    }
}
