#include "JugadorHumano.h"
#include <iostream>
int marcador;
JugadorHumano::JugadorHumano()
{
    tablero.inicializarTablero();
}

JugadorHumano::~JugadorHumano()
{
}

bool JugadorHumano::moverFicha(string cordenadaNueva, string cordenadaActual, char colordeFicha)
{

    string temporal;
    bool bandera;
    bandera = reglas(cordenadaNueva, cordenadaActual, colordeFicha);
    if (bandera)
    {
        temporal = tablero.getFichaActual(posY, posX); //guarda la ficha actual en esa variable
        tablero.setPosicionBlanca(posY, posX);         //quiere decir que la posicion actual queda vacia
        tablero.setAsignarMovimiento(temporal, posyNueva, posxNueva);
        system("cls");
        //aqui el tablero se va actualizando
        return true;
    }
    else
    {
        system("cls");
        return false;
    }
}

bool JugadorHumano::reglas(string cordenadaNueva, string cordenadaActual, char colordeFicha)
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

    if (colordeFicha == 'B' and posY == 0)
    { ///CONDICIONALES DE RETORNO HABILITADO
        poderRetornar(colordeFicha, marcador);
        return true;
    }
    if (colordeFicha == 'N' and posY == 5)
    {
        poderRetornar(colordeFicha, marcador);
        return true;
    }

    //Ficha Blanca a negra
    if ((temporalfichaActual[0] == 'T' and temporalfichaNueva[0] == 'P') and (temporalfichaActual[1] == 'B' and temporalfichaNueva[1] == 'N'))
    {
        juez.setPuntajeJugador1(1);
        return true;
    }

    else if ((temporalfichaActual[0] == 'R' and temporalfichaNueva[0] == 'T') and (temporalfichaActual[1] == 'B' and temporalfichaNueva[1] == 'N'))
    {
        juez.setPuntajeJugador1(1);
        return true;
    }
    else if ((temporalfichaActual[0] == 'P' and temporalfichaNueva[0] == 'R') and (temporalfichaActual[1] == 'B' and temporalfichaNueva[1] == 'N'))
    {
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
        juez.setPuntajeJugador1(1);
        return true;
    }

    else if ((temporalfichaActual[0] == 'R' and temporalfichaNueva[0] == 'T') and (temporalfichaActual[1] == 'N' and temporalfichaNueva[1] == 'B'))
    {

        juez.setPuntajeJugador1(1);
        return true;
    }
    else if ((temporalfichaActual[0] == 'P' and temporalfichaNueva[0] == 'R') and (temporalfichaActual[1] == 'N' and temporalfichaNueva[1] == 'B'))
    {

        juez.setPuntajeJugador1(1);
        return true;
    }
    else
    {
        return false;
    }
}

string JugadorHumano::darNick()
{
    return nick;
}

void JugadorHumano::cambiarNick(string nuevoNick)
{
    nick = nuevoNick;
}

int JugadorHumano::darPuntaje()
{
    return juez.darPuntajeJugador1();
}
void JugadorHumano::setPuntaje(int nuevoPuntaje)
{
    puntaje += nuevoPuntaje;
}

void JugadorHumano::poderRetornar(char color, int puntaje)
{
    //retorno habilitado
    marcador = puntaje;
    string temporal = "";
    if (puntaje > 0)
    {
        if (color == 'B')
        {
            if (posY == 0 and (posX > 0 and posX < 5))
            {
                if (tablero.getFichaActual(1, posY) == "  ")
                {
                    do
                    {
                        fflush(stdin);
                        temporal = "";
                        cout << "Ingrese la ficha que desea agregar" << endl;
                        getline(cin, temporal);
                    } while (temporal != "R" && (temporal != "P") && temporal != "T");
                    temporal += "B";
                    cout << "Hola" << endl;
                    cout << "Pos Y" << posY << endl;
                    cout << "Pos X + 1" << (posX + 1);
                    tablero.setAsignarMovimiento(temporal, posY,5);
                }
                else if (tablero.getFichaActual(1, posY + 1) == "  ")
                {
                    do
                    {
                        fflush(stdin);
                        temporal = "";
                        cout << "Ingrese la ficha que desea agregar" << endl;
                        getline(cin, temporal);
                    } while (temporal != "R" && (temporal != "P") && temporal != "T");
                    temporal += "B";
                    cout << "Hola" << endl;
                    cout << "Pos Y" << posY;
                    cout << "Pos X + 1" << (posX + 1);
                    tablero.setAsignarMovimiento(temporal, posY, posX + 1);
                }
                else
                {
                    cout << "No puede Realizar esta accion" << endl;
                    system("pause");
                }
            }
            if (posY == 0 and (posX == 0))
            {
                if (tablero.getFichaActual(1, posY) == "  ")
                {
                    do
                    {
                        fflush(stdin);
                        temporal = "";
                        cout << "Ingrese la ficha que desea agregar" << endl;
                        getline(cin, temporal);
                    } while (temporal != "R" && (temporal != "P") && temporal != "T");
                    temporal += "B";
                    cout << "Hola" << endl;
                    cout << "Pos Y" << posY;
                    cout << "Pos X + 1" << (posX + 1);
                    tablero.setAsignarMovimiento(temporal, posY, posX + 1);
                }
                else
                {
                    cout << "No puede Realizar esta accion" << endl;
                    system("pause");
                }
            }
            if (posY == 0 and (posX == 5))
            {
                if (tablero.getFichaActual(1, posY) == "  ")
                {
                    do
                    {
                        fflush(stdin);
                        temporal = "";
                        cout << "Ingrese la ficha que desea agregar" << endl;
                        getline(cin, temporal);
                    } while (temporal != "R" && (temporal != "P") && temporal != "T");
                    temporal += "B";
                    cout << "Hola" << endl;
                    cout << "Pos Y" << posY;
                    cout << "Pos X + 1" << (posX + 1);
                    tablero.setAsignarMovimiento(temporal, posY, posX + 1);
                }
                else
                {
                    cout << "No puede Realizar esta accion" << endl;
                    system("pause");
                }
            }
        }
        ////////////////////////////////////////////////////
        if (color == 'N')
        {
            if (posY == 5 and (posX > 0 and posX < 5))
            {
                if (tablero.getFichaActual(0, posX - 1) == "  ")
                {
                    do
                    {
                        fflush(stdin);
                        temporal = "";
                        cout << "Ingrese la ficha que desea agregar" << endl;
                        getline(cin, temporal);
                    } while (temporal != "R" && (temporal != "P") && temporal != "T");
                    temporal += "N";
                    tablero.setAsignarMovimiento(temporal, posY, posX - 1);
                }
                else if (tablero.getFichaActual(0, posX + 1) == "  ")
                {
                    do
                    {
                        fflush(stdin);
                        temporal = "";
                        cout << "Ingrese la ficha que desea agregar" << endl;
                        getline(cin, temporal);
                    } while (temporal != "R" && (temporal != "P") && temporal != "T");
                    temporal += "N";
                    tablero.setAsignarMovimiento(temporal, posY, posX + 1);
                }
                else
                {
                    cout << "No puede Realizar esta accion" << endl;
                    system("pause");
                }
            }
            if (posY == 5 and (posX == 0))
            {
                if (tablero.getFichaActual(0, posX + 1) == "  ")
                {
                    do
                    {
                        fflush(stdin);
                        temporal = "";
                        cout << "Ingrese la ficha que desea agregar" << endl;
                        getline(cin, temporal);
                    } while (temporal != "R" && (temporal != "P") && temporal != "T");
                    temporal += "N";
                    tablero.setAsignarMovimiento(temporal, posY, posX - 1);
                }
                else
                {
                    cout << "No puede Realizar esta accion" << endl;
                    system("pause");
                }
            }
            if (posY == 5 and (posX == 5))
            {
                if (tablero.getFichaActual(0, posX - 1) == "  ")
                {
                    do
                    {

                        fflush(stdin);
                        temporal = "";
                        cout << "Ingrese la ficha que desea agregar" << endl;
                        getline(cin, temporal);
                    } while (temporal != "R" && (temporal != "P") && temporal != "T");
                    temporal += "N";
                    tablero.setAsignarMovimiento(temporal, posY, posX - 1);
                }
                else
                {
                    cout << "No puede Realizar esta accion" << endl;
                    system("pause");
                }
            }
        }
    }
}