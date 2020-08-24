#include "Tablero.h"
#include <iostream>
using namespace std;

Tablero::Tablero()
{
}

Tablero::~Tablero()
{
}

void Tablero::mostrarTablero()
{

    for (int i = 0; i < 6; i++)
    {
        vector<Ficha>fichas;
        for (int j = 0; j < 6; j++)
        {
            if ((i == 0 and j == 0) or (i == 1 and j == 0) or (i == 0 and j == 3) or (i == 1 and j == 3))
            {
               //Tijera Negra
            }
            else if ((i == 0 and j == 1) or (i == 1 and j == 1) or (i == 0 and j == 4) or (i == 1 and j == 4))
            {
                //Papel Negra
            }
            else if ((i == 0 and j == 2) or (i == 1 and j == 2) or (i == 0 and j == 5) or (i == 1 and j == 5))
            {
                //Roca Negra
            }
            //Ficha Blanca
            else if ((i == 4 and j == 0) or (i == 5 and j == 0) or (i == 4 and j == 3) or (i == 5 and j == 3))
            {
                //Tijera Blanca
            }
            else if ((i == 4 and j == 1) or (i == 5 and j == 1) or (i == 4 and j == 4) or (i == 5 and j == 4))
            {
                //Papel Blanco
            }
            else if ((i == 4 and j == 2) or (i == 5 and j == 2) or (i == 4 and j == 5) or (i == 5 and j == 5))
            {
                //Roca Negra
            }
            else
            {
                
            }
            tablerito.push_back(fichas);
        }
        
    }

    /*for (int i = 0; i < tablerito.size(); i++)
    {
        for (int j = 0; j < tablerito[i].size(); j++)
        {
            cout << tablerito[i][j] << " | "<<endl;
        }
        cout << endl;
    }*/
}



bool Tablero::hayUnaFichaEnUnaPosicion(int x, int y)
{
}

bool Tablero::esVaciaUnaPosicion(int x, int y)
{
    if (x=0, y=0) true;
    {
     false;
    }
    
  
}

bool Tablero::puedeMoverseFicha(int x, int y)
{
    if ( esVaciaUnaPosicion( x,  y)) true;
    {
        false;
    }
    
}

void Tablero::moverFicha(int actualX, int actualY, int nuevaX, int nuevaY)
{
}

int Tablero::pos_Y_PrimeraFichaEnAparecer(int color)
{
}

int Tablero::pos_X_PrimeraFichaEnAparecer(int color)
{
}

Ficha Tablero::darFicha(int x, int y)
{
}

bool Tablero::retornoHabilitado(int x, int y)
{
}

bool Tablero::puedeHacerRetorno(int actualx, int actualy, int nuevax, int nuevay)
{
}
