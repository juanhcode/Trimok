#include "Tablero.h"
#include <iostream>
#include <vector>
#include <string.h>
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
                    Ficha tijeraN(2, "TN", 0, 0);
                    fichaActual.push_back(tijeraN);
                }
                else if (j == 1 or j == 4)
                {
                    Ficha papelN(2, "PN", 0, 0);
                    fichaActual.push_back(papelN);
                }
                else if (j == 2 or j == 5)
                {
                    Ficha RocaN(2, "RN", 0, 0);
                    fichaActual.push_back(RocaN);
                }
            }
            else if (i == 4 or i == 5)
            {
                if (j == 0 or j == 3)
                {
                    Ficha tijeraB(1, "TB", 0, 0);
                    fichaActual.push_back(tijeraB);
                }
                else if (j == 1 or j == 4)
                {
                    Ficha papelB(1, "PB", 0, 0);
                    fichaActual.push_back(papelB);
                }
                else if (j == 2 or j == 5)
                {
                    Ficha RocaB(1, "RB", 0, 0);
                    fichaActual.push_back(RocaB);
                }
            }
            else
            {
                Ficha vacia(3, "  ", 0, 0);
                fichaActual.push_back(vacia);
            }
        }
        tablerito.push_back(fichaActual);
    }
}

void Tablero::mostrarTablero()
{
    string mensaje;
    cout << "_________________________________" << endl;
    for (int i = 0; i < tablerito.size(); i++)
    {
        cout << 6 - i << " | ";
        for (int j = 0; j < tablerito.size(); j++)
        {

            /*if (tablerito[i][j].darColor() == 1)
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
            }*/
            cout << mensaje << tablerito[i][j].darTipo() << " | ";
        }
        cout << endl;
    }
    cout << "    A    B    C    D    E    F" << endl;
}

bool Tablero::hayUnaFichaEnUnaPosicion(int x, int y)
{
    //si la casilla es igual a B o N entonces la posicion esta ocupada en la posicion x y
}

bool Tablero::esVaciaUnaPosicion(int x, string y)
{
    string columna = "ABCDEF";
    int posicionColumna;

    for (int i = 0; i < columna.length(); i++)
    {
        /*if (y == columna[i])
        {
            posicionColumna = i;
        }*/
    }

    /*for (int i = 0; i < tablerito.size(); i++)
    {
        for (int j = 0; j < tablerito.size(); j++)
        {
            if (tablerito[i][j].darTipo() == 4)
            {
                return true;
            }
        }
    }*/
    //1 = Piedra, 2 = Papel, 3 = Tijera, 4 = vacio
    //cout << tablerito[0][0].darTipo() << "es" << endl;
    return false;
}

int Tablero::verificarPosicion(int x, char y)
{

    char columna[] = "ABCDEF";
    int posicionColumna;

    for (int i = 0; i < strlen(columna); i++)
    {
        if (columna[i] == y)
        {
            posicionColumna = i;
        }
    }
    return posicionColumna;
}

void Tablero::borrarFicha(string cordenada)
{
    string x = "ABCDEF";
    string y = "123456";
}

bool Tablero::puedeMoverseFicha(int x, int y)
{
    //si se cumple con las condiciones se puede mover la ficha
}

void Tablero::moverFicha(string cordenadaNueva, string cordenadaActual)
{
    int posX;
    int posY;
    int posxNueva;
    int posyNueva;
    string temporal;
    string x = "ABCDEF";
    string y = "654321";

    for (int i = 0; i < 6; i++)
    {
        if (cordenadaActual[0] == x[i])
        {
            posX = i;
            //cout << "Esta es la posicion actual de X: " << posX << endl;
        }
        if (cordenadaActual[1] == y[i])
        {
            posY = i;
            //cout << "Esta es la posicion actual de Y: " << posY << endl;
        }

        if (cordenadaNueva[0] == x[i])
        {
            posxNueva = i;
            //cout << "Esta es la  nueva posicion de X: " << posxNueva << endl;
        }
        if (cordenadaNueva[1] == y[i])
        {
            posyNueva = i;
            //cout << "Esta es la  nueva posicion de y: " << posyNueva << endl;
        }
    }
    temporal = tablerito[posY][posX].darTipo();
    //cout << "Esto es temporal" << temporal << endl;
    tablerito[posY][posX].cambiarTipo("  "); //quiere decir que la posicion actual queda vacia
    tablerito[posyNueva][posxNueva].cambiarTipo(temporal);
    mostrarTablero();
}

bool Tablero::reglas(string posicion){
    
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
    en ese caso se podra hacer  el retorno */
}