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
	cout<<"Jugador Blanco"<<"\t";                                              cout<<"\tJugador Negro"<<endl;
	cout<<"Ficha:"<<"\t"<<"\t";													   cout<<"\tFicha:"<<endl;
}

/*void Trimok::play(){

	string fichaActual;
	string fichaMovida;
	cout<<"ingresar la ficha que desee mover: "<<endl;
	cin>>fichaActual;
	cout<<fichaActual<<endl;
	fichas.setFicha(fichaActual);
	fichaActual=fichas.darFicha();
	cout<<fichaActual<<endl;
}*/