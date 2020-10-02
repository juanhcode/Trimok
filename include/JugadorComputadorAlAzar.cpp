#include "JugadorComputadorAlAzar.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#include "time.h"
int marcadorMaquina;

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
    posX = atoi(cordenadaActual.c_str()) / 10;
    posY = atoi(cordenadaActual.c_str()) % 10;
    posxNueva = atoi(cordenadaNueva.c_str()) / 10;
    posyNueva = atoi(cordenadaNueva.c_str()) % 10;

    //en ves de el for para la maquina vamos a generar numeros aleatorios entre 0 y 5
    string temporalfichaActual; //guarda temporarlmente la ficha en esta variable
    string temporalfichaNueva;  //guarda temporarlmente la ficha en esta variable
    bool diagonal = false;

    temporalfichaActual = tablero.getFichaActual(posY, posX);
    temporalfichaNueva = tablero.getFichaActual(posyNueva, posxNueva);

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
        juez.setPuntajeJugador1(1);
        return true;
    }

    else if ((temporalfichaActual[0] == 'R' and temporalfichaNueva[0] == 'T') and (temporalfichaActual[1] == 'B' and temporalfichaNueva[1] == 'N'))
    {
        //jugador.setPuntaje(1);
        juez.setPuntajeJugador1(1);
        return true;
    }
    else if ((temporalfichaActual[0] == 'P' and temporalfichaNueva[0] == 'R') and (temporalfichaActual[1] == 'B' and temporalfichaNueva[1] == 'N'))
    {
        //jugador.setPuntaje(1);
        juez.setPuntajeJugador1(1);
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
        juez.setPuntajeJugador1(1);
        return true;
    }

    else if ((temporalfichaActual[0] == 'R' and temporalfichaNueva[0] == 'T') and (temporalfichaActual[1] == 'N' and temporalfichaNueva[1] == 'B'))
    {
        //jugador.setPuntaje(1);
        juez.setPuntajeJugador1(1);
        return true;
    }
    else if ((temporalfichaActual[0] == 'P' and temporalfichaNueva[0] == 'R') and (temporalfichaActual[1] == 'N' and temporalfichaNueva[1] == 'B'))
    {
        //jugador.setPuntaje(1);
        juez.setPuntajeJugador1(1);
        return true;
    }
    else
    {
        return false;
    }
}

string JugadorComputadorAlAzar::darNick()
{
    return nick;
}

void JugadorComputadorAlAzar::cambiarNick(string nuevoNick)
{
    nick = nuevoNick;
}

int JugadorComputadorAlAzar::darPuntaje()
{
    return juez.darPuntajeJugador1();
}
void JugadorComputadorAlAzar::setPuntaje(int nuevoPuntaje)
{
    puntaje += nuevoPuntaje;
}

void JugadorComputadorAlAzar::poderRetornar(char color, int puntaje)
{
    //Retorno
    marcadorMaquina = puntaje;
    string temporal = "";
    if (puntaje < 12)
    {
        if (color == 'B')
        {
            if (posY == 0 and (posX > 0 and posX < 5))
            {
                if (tablero.getFichaActual(5, posX - 1) == " ")
                {
                    do
                    {
                        cout << "Ingrese la ficha que desea agregar" << endl;
                        cin >> temporal;
                    } while (temporal != "R" or (temporal != "P") or temporal != "T");
                    temporal += "B";
                    tablero.setAsignarMovimiento(temporal, posY, posX - 1);
                }
                else if (tablero.getFichaActual(5, posX + 1) == " ")
                {
                    do
                    {
                        cout << "Ingrese la ficha que desea agregar" << endl;
                        cin >> temporal;
                    } while (temporal != "R" or (temporal != "P") or temporal != "T");
                    temporal += "B";
                    tablero.setAsignarMovimiento(temporal, posY, posX + 1);
                }
                else
                {
                    cout << "No puede Realizar esta accion" << endl;
                }
            }
            if (posY == 0 and (posX == 0))
            {
                if (tablero.getFichaActual(5, posX + 1) == " ")
                {
                    do
                    {
                        cout << "Ingrese la ficha que desea agregar" << endl;
                        cin >> temporal;
                    } while (temporal != "R" or (temporal != "P") or temporal != "T");
                    temporal += "B";
                    tablero.setAsignarMovimiento(temporal, posY, posX - 1);
                }
                else
                {
                    cout << "No puede Realizar esta accion" << endl;
                }
            }
            if (posY == 0 and (posX == 5))
            {
                if (tablero.getFichaActual(5, posX - 1) == " ")
                {
                    do
                    {
                        cout << "Ingrese la ficha que desea agregar" << endl;
                        cin >> temporal;
                    } while (temporal != "R" or (temporal != "P") or temporal != "T");
                    temporal += "B";
                    tablero.setAsignarMovimiento(temporal, posY, posX - 1);
                }
                else
                {
                    cout << "No puede Realizar esta accion" << endl;
                }
            }
        }
        ////////////////////////////////////////////////////
        if (color == 'N')
        {
            if (posY == 5 and (posX > 0 and posX < 5))
            {
                if (tablero.getFichaActual(0, posX - 1) == " ")
                {
                    do
                    {
                        cout << "Ingrese la ficha que desea agregar" << endl;
                        cin >> temporal;
                    } while (temporal != "R" or (temporal != "P") or temporal != "T");
                    temporal += "N";
                    tablero.setAsignarMovimiento(temporal, posY, posX - 1);
                }
                else if (tablero.getFichaActual(0, posX + 1) == " ")
                {
                    do
                    {
                        cout << "Ingrese la ficha que desea agregar" << endl;
                        cin >> temporal;
                    } while (temporal != "R" or (temporal != "P") or temporal != "T");
                    temporal += "N";
                    tablero.setAsignarMovimiento(temporal, posY, posX + 1);
                }
                else
                {
                    cout << "No puede Realizar esta accion" << endl;
                }
            }
            if (posY == 5 and (posX == 0))
            {
                if (tablero.getFichaActual(0, posX + 1) == " ")
                {
                    do
                    {
                        cout << "Ingrese la ficha que desea agregar" << endl;
                        cin >> temporal;
                    } while (temporal != "R" or (temporal != "P") or temporal != "T");
                    temporal += "N";
                    tablero.setAsignarMovimiento(temporal, posY, posX - 1);
                }
                else
                {
                    cout << "No puede Realizar esta accion" << endl;
                }
            }
            if (posY == 5 and (posX == 5))
            {
                if (tablero.getFichaActual(0, posX - 1) == " ")
                {
                    do
                    {
                        cout << "Ingrese la ficha que desea agregar" << endl;
                        cin >> temporal;
                    } while (temporal != "R" or (temporal != "P") or temporal != "T");
                    temporal += "N";
                    tablero.setAsignarMovimiento(temporal, posY, posX - 1);
                }
                else
                {
                    cout << "No puede Realizar esta accion" << endl;
                }
            }
        }
    }
}