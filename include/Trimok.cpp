#include "Trimok.h"
#include <iostream>
using namespace std;
Trimok::Trimok()
{
	opcionParaEljugador = 0;
}

Trimok::~Trimok()
{
	//Destructor
}

void Trimok::seleccionarOpcion()
{
	cout << endl;
	cout << "  JUEGO  TRIMOK" << endl;
	cout << "1- Instrucciones" << endl;
	cout << "2- Jugar" << endl;
	cout << "3- Salir" << endl;
	do
	{
		cout << "Introduzca Opcion: " << endl;
		cin >> opcion;
	} while (!((opcion >= 1) && (opcion <= 3)));
}

void Trimok::visualizar()
{
	do
	{
		seleccionarOpcion();
		{
			switch (opcion)
			{
			case 1:
				cout << "para mover ficha ingresa la letra mayuscula y un numero " << endl;
				cout << "solo se puede mover una posicion" << endl;
				cout << "..............................................................." << endl;

				cout << "Jugador Blanco" << endl;
				cout << "Tijeras blancas toman el papel negro " << endl;
				cout << "Papel blanco toma la roca negra" << endl;
				cout << "La roca blanca toman tijeras negras" << endl;
				cout << "---------------------------------------------" << endl;

				cout << "Jugador Negro" << endl;
				cout << "Tijeras negras toman el papel blanco" << endl;
				cout << "Papel negro toma la roca blanca" << endl;
				cout << "La roca negra toman tijeras blancas" << endl;
				cout << "---------------------------------------------" << endl;
				system("pause");
				break;
			case 2:
				obtenerNick();
				mostrarDatos();
				e.inicializarTablero();
				cout << "                   :::TRIMOK:::                       " << endl;
				e.mostrarTablero();
				play();
				system("pause");
				break;
				break;
			}
			system("cls");
		}

	} while (opcion != 3);
}
void Trimok::mostrarDatos()
{
	//cout<<"Jugador Blanco"<<"\t";                                              cout<<"\tJugador Negro"<<endl;
	cout << "Jugador Blanco: " << jugadorB.darNick() << "\t";
	cout << "\tJugador Negro: " << jugadorN.darNick();
}
void Trimok::obtenerNick()
{
	string nickJugadorB;
	string nickJugadorN;

	cout << "Digite el Nick de el jugador blanco: " << endl;
	cin >> nickJugadorB;
	nickJugadorB = jugadorB.cambiarNick(nickJugadorB);
	cout << "Digite el Nick de el jugador Negro" << endl;
	cin >> nickJugadorN;
	nickJugadorN = jugadorN.cambiarNick(nickJugadorN);
}
void Trimok::play()
{
	bool bandera;
	bool ganador = true;
	string posActual, posNueva;

	while (ganador)
	{
		bandera = false;
		//si bandera es diferente a verdadero entra al while
		while (bandera != true)
		{
			while (bandera != true)
			{
				cout << "Puntaje " << jugadorB.darNick() << ":" << jugadorB.darPuntaje() << endl;
				if (jugadorB.darPuntaje() > 11)
				{
					cout << "Ganaste!!" << jugadorB.darNick();
				}
				else if (jugadorN.darPuntaje() > 11)
				{
					cout << "Ganaste!!" << jugadorN.darNick();
				}
				cout << jugadorB.darNick() << "--> "
					 << "Ingrese la Posicion actual" << endl;
				cin >> posActual;
				cout << jugadorB.darNick() << "--> "
					 << "Ingrese la Posicion que desee mover" << endl;
				cin >> posNueva;
				bandera = e.moverFicha(posNueva, posActual, 'B', jugadorB);
				//retorna verdadero si la regla se cumple
			}
		}
		bandera = false;
		while (bandera != true)
		{

			cout << "Puntaje " << jugadorN.darNick() << ":" << jugadorN.darPuntaje() << endl;
			cout << jugadorN.darNick() << "--> "
				 << "Ingrese la Posicion actual " << endl;
			cin >> posActual;
			cout << jugadorN.darNick() << "--> "
				 << "Ingrese la Posicion que desee mover" << endl;
			cin >> posNueva;
			bandera = e.moverFicha(posNueva, posActual, 'N', jugadorN);
		}
	}
}
