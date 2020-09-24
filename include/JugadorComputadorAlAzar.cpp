#include "JugadorComputadorAlAzar.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#include "time.h"

JugadorComputadorAlAzar::JugadorComputadorAlAzar()
{
    nick = "Maquina";
    tablero.inicializarTablero();
}

JugadorComputadorAlAzar::~JugadorComputadorAlAzar()
{
}

bool JugadorComputadorAlAzar::moverFicha(string cordenadaNueva, string cordenadaActual, char colordeFicha)
//PARA LA MAQUINA ES LO MISMO SOLO QUE COMO ARGUMENTO NOS VA RECIBIR COLOR DE LA FICHA
{

    string temporal;
    bool bandera;
    bandera = reglas(cordenadaNueva, cordenadaActual, colordeFicha);
    //Para la maquina solo va recibir como argumento el color de la ficha
    if (bandera)
    {
        temporal = tablero.getFichaActual(posY, posX); //guarda la ficha actual en esa variable
        tablero.setPosicionBlanca(posY, posX);         //quiere decir que la posicion actual queda vacia
        tablero.setAsignarMovimiento(temporal, posyNueva, posxNueva);
        //tablero.darTablerito()[posyNueva][posxNueva].cambiarTipo(temporal);
        //system("cls");
        //aqui el tablero se va actualizando
        //tablero.mostrarTablero();
        return true;
    }
    else
    {
        //system("cls");
        //tablero.mostrarTablero();
        return false;
    }
}

bool JugadorComputadorAlAzar::reglas(string cordenadaNueva, string cordenadaActual, char colordeFicha)
{
    /*string temporal;
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
    }*/
    posX = atoi(cordenadaActual.c_str()) / 10;
    posY = atoi(cordenadaActual.c_str()) % 10;
    posxNueva = atoi(cordenadaNueva.c_str()) / 10;
    posyNueva = atoi(cordenadaNueva.c_str()) % 10;

    //en ves de el for para la maquina vamos a generar numeros aleatorios entre 0 y 5
    string temporalfichaActual; //guarda temporarlmente la ficha en esta variable
    string temporalfichaNueva;  //guarda temporarlmente la ficha en esta variable
    bool diagonal = false;
    //cout << "este es mi valor "<<posY<<"----"<<posX;

    temporalfichaActual = tablero.getFichaActual(posY, posX);
    temporalfichaNueva = tablero.getFichaActual(posyNueva, posxNueva);
    //cout << "Actual" << temporalfichaActual << endl;
    //cout << "Nueva" << temporalfichaNueva << endl;

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
        //jugador.setPuntaje(1);
        return true;
    }

    else if ((temporalfichaActual[0] == 'R' and temporalfichaNueva[0] == 'T') and (temporalfichaActual[1] == 'B' and temporalfichaNueva[1] == 'N'))
    {
        //jugador.setPuntaje(1);
        return true;
    }
    else if ((temporalfichaActual[0] == 'P' and temporalfichaNueva[0] == 'R') and (temporalfichaActual[1] == 'B' and temporalfichaNueva[1] == 'N'))
    {
        //jugador.setPuntaje(1);
        return true;
    }
    else if (temporalfichaNueva == "  ")
    {
        return true;
    }

    //ficha negra a blanca
    else if ((temporalfichaActual[0] == 'T' and temporalfichaNueva[0] == 'P') and (temporalfichaActual[1] == 'N' and temporalfichaNueva[1] == 'B'))
    {
        //jugador.setPuntaje(1);
        return true;
    }

    else if ((temporalfichaActual[0] == 'R' and temporalfichaNueva[0] == 'T') and (temporalfichaActual[1] == 'N' and temporalfichaNueva[1] == 'B'))
    {
        //jugador.setPuntaje(1);
        return true;
    }
    else if ((temporalfichaActual[0] == 'P' and temporalfichaNueva[0] == 'R') and (temporalfichaActual[1] == 'N' and temporalfichaNueva[1] == 'B'))
    {
        //jugador.setPuntaje(1);
        return true;
    }
    else
    {
        return false;
    }

    /*if (((posX < 0) or (posX > 5)) and ((posxNueva < 0) or (posxNueva > 5)))
    {
        system("pause");
        return false;
    }
    if (((posY < 0) or (posY > 5)) and ((posyNueva < 0) or (posyNueva > 5)))
    {
        system("pause");
        return false;
    }*/

    
}

string JugadorComputadorAlAzar::darNick()
{
    return nick;
}

string JugadorComputadorAlAzar::cambiarNick(string nuevoNick)
{
    nick = nuevoNick;
}

int JugadorComputadorAlAzar::darPuntaje()
{
    return puntaje;
}
void JugadorComputadorAlAzar::setPuntaje(int nuevoPuntaje)
{
    puntaje += nuevoPuntaje;
}