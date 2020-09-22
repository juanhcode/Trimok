#include "Tablero.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
using namespace std;
//variables globales
int posX;
int posY;
int posxNueva;
int posyNueva;
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
    //aqui se imprime el tablero
    //cout << endl;
    //cout<<"                   :::TRIMOK:::                       "<<endl;
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
bool Tablero::moverFicha(string cordenadaNueva, string cordenadaActual, char colordeFicha, Jugador &jugador)
{

    string temporal;
    bool bandera;
    bandera = reglas(cordenadaNueva, cordenadaActual, colordeFicha, jugador);
    if (bandera)
    {
        temporal = tablerito[posY][posX].darTipo(); //guarda la ficha actual en esa variable
        tablerito[posY][posX].cambiarTipo("  ");    //quiere decir que la posicion actual queda vacia
        tablerito[posyNueva][posxNueva].cambiarTipo(temporal);
        system("cls");
        //aqui el tablero se va actualizando
        mostrarTablero();
        return true;
    }
    else
    {
        system("cls");
        mostrarTablero();
        return false;
    }
}

/*bool Tablero::reglas(string cordenadaNueva, string cordenadaActual, char colordeFicha, Jugador &jugador)
{
    string temporal;
    string x = "ABCDEF";
    string y = "654321";
    //coordenada tanto actual como nueva
    //verifica si existe la coordenada que ingrese con el tablero
    for (int i = 0; i < 6; i++)
    {
        if (cordenadaActual[0] == x[i])
        {
            posX = i;
            //se verifica la cordenada actual
        }
        if (cordenadaActual[1] == y[i])
        {
            posY = i;
        }

        if (cordenadaNueva[0] == x[i])
        {
            posxNueva = i;
        }
        if (cordenadaNueva[1] == y[i])
        {
            posyNueva = i;
        }
    }

    string temporalfichaActual; //guarda temporarlmente la ficha en esta variable
    string temporalfichaNueva;  //guarda temporarlmente la ficha en esta variable
    bool diagonal = false;
    temporalfichaActual = tablerito[posY][posX].darTipo();
    temporalfichaNueva = tablerito[posyNueva][posxNueva].darTipo();

    //condicional para que el jugador blanco o negro solamente pueda jugar con las fichas que le corresponde
    if (temporalfichaActual[1] != colordeFicha)
    {
        return false;
    }

    //REGLA PARA QUE EL JUGADOR  SOLO PUEDA MOVER FICHAS A ESPACIOS VACIOS NO MONTAR ENCIMA DE LA OTRA
    if ((temporalfichaActual[1] == temporalfichaNueva[1]))
    {
        return false;
    }


    //MOVER ESA FICHA EN HORIZONTAL , VERTICAL Y DIAGONAL
    if ((abs(posX - posxNueva) == 1) and (abs(posY - posyNueva) == 1))
    {
        diagonal = true;
        //diagonal
    }
    if ((abs(posX - posxNueva) == 1) and (posY - posyNueva == 0))
    {
        diagonal = true;
        //Hori
    }
    if ((posX - posxNueva == 0) and (abs(posY - posyNueva) == 1))
    {
        diagonal = true;
        //Ver
    }
    if (diagonal == false)
    {
        return false;
    }

    //Ficha Blanca a negra
    if ((temporalfichaActual[0] == 'T' and temporalfichaNueva[0] == 'P') and (temporalfichaActual[1] == 'B' and temporalfichaNueva[1] == 'N'))
    {
        jugador.setPuntaje(1);
        return true;
    }

    else if ((temporalfichaActual[0] == 'R' and temporalfichaNueva[0] == 'T') and (temporalfichaActual[1] == 'B' and temporalfichaNueva[1] == 'N'))
    {
        jugador.setPuntaje(1);
        return true;
    }
    else if ((temporalfichaActual[0] == 'P' and temporalfichaNueva[0] == 'R') and (temporalfichaActual[1] == 'B' and temporalfichaNueva[1] == 'N'))
    {
        jugador.setPuntaje(1);
        return true;
    }
    else if (temporalfichaNueva == "  ")
    {
        return true;
    }

    //ficha negra a blanca
    else if ((temporalfichaActual[0] == 'T' and temporalfichaNueva[0] == 'P') and (temporalfichaActual[1] == 'N' and temporalfichaNueva[1] == 'B'))
    {
        jugador.setPuntaje(1);
        return true;
    }

    else if ((temporalfichaActual[0] == 'R' and temporalfichaNueva[0] == 'T') and (temporalfichaActual[1] == 'N' and temporalfichaNueva[1] == 'B'))
    {
        jugador.setPuntaje(1);
        return true;
    }
    else if ((temporalfichaActual[0] == 'P' and temporalfichaNueva[0] == 'R') and (temporalfichaActual[1] == 'N' and temporalfichaNueva[1] == 'B'))
    {
        jugador.setPuntaje(1);
        return true;
    }
    else
    {
        return false;
    }
}*/

bool Tablero::rangoTablero()
{
    //condicion para que la ficha este dentro del rango del tablero
    if (((posX < 0) or (posX > 5)) and ((posxNueva < 0) or (posxNueva > 5)))
    {
        cout << "opcion invalida :( " << endl;
        system("pause");
        return false;
    }
    if (((posY < 0) or (posY > 5)) and ((posyNueva < 0) or (posyNueva > 5)))
    {
        cout << "opcion invalida :( " << endl;
        system("pause");
        return false;
    }
}

bool Tablero::retornoHabilitado(int x, int y)
{
}

bool Tablero::puedeHacerRetorno(int actualx, int actualy, int nuevax, int nuevay)
{
    /*para hacer el retorno se nesecita mirar si la ficha que llega esta sola en su fila correspondiente
    en ese caso se podra hacer  el retorno */
}

vector<vector<Ficha>> Tablero::darTablerito(){

    return tablerito;
}