#include "Trimok.h"
#include <iostream>
using namespace std;
Trimok::Trimok()
{
	Ficha Tijera(1, 3, 0, 4);
	Tablero tablerito();
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
				cout << "Jugador Blanco" << endl;
				cout << "tijeras blancas toman el papel negro " << endl;
				cout << "papel blanco toma la roca negra" << endl;
				cout << "la roca blanca toman tijeras negras" << endl;
				cout << "---------------------------------------------" << endl;

				cout << "Jugador Negro" << endl;
				cout << "tijeras negras toman el papel blanco" << endl;
				cout << "papel negro toma la roca blanca" << endl;
				cout << "la roca negra toman tijeras blancas" << endl;
				cout << "---------------------------------------------" << endl;
				system("pause");
				break;
			case 2:
				escogerJugador();
				break;
			}
			system("cls");
		}

	} while (opcion != 3);
}

void Trimok::mostrarDatos()
{
	  
}

void Trimok::seleccionJugador()
{

	cout << "Escoge el Jugador" << endl;
	cout << "1 - Jugador Blanco" << endl;
	cout << "2 - Jugador Negro" << endl;
	cout << "3 - Volver al menu" << endl;
	do
	{
		cout << "Introduzca Opcion: " << endl;
		cin >> opcion;
	} while (!((opcion >= 1) && (opcion <= 3)));
}
void Trimok::escogerJugador()
{
	do
	{
		seleccionJugador();
		{
			switch (opcion)
			{
			case 1:
				mostrarDatos();
				break;
			case 2:
				/* code */
				break;

			default:
				break;
			}
			system("cls");
		}
	} while (opcion != 3);
}