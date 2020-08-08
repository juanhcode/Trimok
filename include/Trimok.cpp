#include "Trimok.h"
#include <iostream>
using namespace std;
Trimok::Trimok()
{
	Ficha Tijera(1,3,0,4);
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
		//mostrarDatosPersonales();
		//mostrarCalculos();
		seleccionarOpcion();
		{
			switch (opcion)
			{
			case 1:
				cout << "Reglas" << endl;
				cin>>opcion;
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

void Trimok::escogerJugador()
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

	do
	{
		switch (opcion)
		{
		case 1:
			/* code */
			break;
		case 2:
			/* code */
			break;

		default:
			break;
		}
	} while (opcion != 3);
}