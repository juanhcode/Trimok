#include "Tablero.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
using namespace std;
//variables globales
std::vector<std::vector<Ficha>> Tablero::tablerito;
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

    cout << "                   :::TRIMOK:::                       " << endl;
    cout << "    __________________________________________" << endl;
    for (int i = 0; i < tablerito.size(); i++)
    {
        cout << 6 - i << "  |  ";
        for (int j = 0; j < tablerito.size(); j++)
        {
            cout << tablerito[i][j].darTipo() << "  |  ";
        }
        cout << "\n   |------|------|------|------|------|------|";
        if (i == 0)
        {
            cout << "\t\t\t Jugador Blanco || Jugador Negro";
        }
        else if (i == 1)
        {
            cout << "\t\t\t RB: Roca Blanca || RN: Roca Negra";
        }
        else if (i == 2)
        {
            cout << "\t\t\t TB: Tijera Blanca || TN: Tijera Negra";
        }
        else if (i == 3)
        {
            cout << "\t\t\t PB: Papel blanco||PN: Papel Negro";
        }
        cout << endl;
    }

    cout << "      A      B      C      D      E      F" << endl;
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
bool Tablero::moverFicha(string cordenadaNueva, string cordenadaActual, char colordeFicha)
{
}

bool Tablero::rangoTablero()
{
}
bool Tablero::retornoHabilitado(int x, int y)
{
}

bool Tablero::puedeHacerRetorno(int actualx, int actualy, int nuevax, int nuevay)
{
}

vector<vector<Ficha>> Tablero::darTablerito()
{

    return tablerito;
}

string Tablero::getFichaActual(int posX, int posY)
{
    string temporal;
    temporal = tablerito[posX][posY].darTipo();
    return temporal;
}

void Tablero::setPosicionBlanca(int posX, int posY)
{
    tablerito[posX][posY].cambiarTipo("  "); //quiere decir que la posicion actual queda vacia
}

void Tablero::setAsignarMovimiento(string temporal, int posyNueva, int posxNueva)
{
    tablerito[posyNueva][posxNueva].cambiarTipo(temporal);
}

//Metodo para el de retornar Movimiento
bool Tablero::setAsignarMovimiento(string temporal)
{
    bool resultado = false;
    for (int i = 0; i < 5; i++)
    {
        if (tablerito[5][i].darTipo() == "  ")
        {
            resultado = true;
            tablerito[5][i].cambiarTipo(temporal);
            break;
        }
    }
    return resultado;
}
