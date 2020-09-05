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
			 	cout <<"para mover ficha ingresa la letra mayuscula y un numero "<<endl;
				cout <<"solo se puede mover una posicion"<<endl;
				cout <<"..............................................................."<<endl;


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
				escogerJugador();
				break;
			}
			system("cls");
		}

	} while (opcion != 3);
}

void Trimok::seleccionJugador()
{

	cout << "Escoge el Jugador" << endl;
	cout << "1 - Jugador Blanco" << endl;
	cout << "2 - Jugador Negro" << endl;
	cout << "3 - Menu" << endl;

	do
	{
		cout << "Introduzca Opcion: " << endl;
		cin >> opcionParaEljugador;
	} while (!((opcionParaEljugador >= 1) && (opcionParaEljugador <= 3)));
}
void Trimok::escogerJugador()
{
	do
	{
		seleccionJugador();
		{
			switch (opcionParaEljugador)
			{
			case 1:
				mostrarDatos();
				e.inicializarTablero();
				e.mostrarTablero();
				play();
				system("pause");
				break;
			case 2:
				break;

			default:
				break;
			}
			system("cls");
		}
	} while (opcionParaEljugador != 3);
}

void Trimok::mostrarDatos()
{
	cout << "Jugador Blanco"
		 << "\t";
	cout << "\tJugador Negro" << endl;
	cout << "Ficha:"
		 << "\t"
		 << "\t";
	cout << "\tFicha:" << endl;
}

void Trimok::play()
{
	bool bandera;
	bool ganador = true;
	string posActual, posNueva;

	while (ganador)
	{
		bandera = false;
		while (bandera != true)
		{
			while (bandera != true)
			{
				cout << "Ingrese la Posicion del Jugador 1" << endl;
				cin >> posActual;
				cout << "Ingrese la Posicion que desee mover Jugador 1" << endl;
				cin >> posNueva;
				bandera = e.moverFicha(posNueva, posActual,'B');
			}
		}
		bandera = false;
		while (bandera != true)
		{

			cout << "Ingrese la Posicion actual Jugador 2" << endl;
			cin >> posActual;
			cout << "Ingrese la Posicion que desee mover Jugador 2" << endl;
			cin >> posNueva;
			bandera = e.moverFicha(posNueva, posActual,'N');
		}
	}
}
