#include "Trimok.h"
#include <iostream>
#include <time.h>
#include <string.h>
using namespace std;
Trimok::Trimok()
{
	opcionParaEljugador = 0;
	opcionParejas = 0;
	opcion = 0;
}
string nickJugadorB;
string nickJugadorN;

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
				visualizarParejas();
			}
			system("cls");
		}

	} while (opcion != 3);
}
void Trimok::seleccionarParejas()
{

	cout << "  Tipo de Juego" << endl;
	cout << "1- JugadorHumano vs JugadorHumano" << endl;
	cout << "2- JugadorComputadorAlAzar vs JugadorHumano" << endl;
	cout << "3- JugadorHumano vs JugadorComputadorAlAzar" << endl;
	cout << "4- JugadorComputadorAlAzar vs JugadorComputadorAlAzar" << endl;
	cout << "5- Salir" << endl;
	do
	{
		cout << "Introduzca Opcion: " << endl;
		cin >> opcionParejas;
	} while (!((opcionParejas >= 1) && (opcionParejas <= 5)));
}

void Trimok::visualizarParejas()
{
	do
	{
		seleccionarParejas();
		{
			switch (opcionParejas)
			{
			case 1:
				obtenerNick();
				mostrarDatos();
				e.inicializarTablero();
				cout << "                   :::TRIMOK:::                       " << endl;
				//e.mostrarTablero();
				play();
				system("pause");
				break;

			case 2:
				cout << "Digite el Nick de el jugador Negro:" << endl;
				cin >> nickJugadorB;
				obtenerNick2(*jugadorNegro, nickJugadorB);
				e.inicializarTablero();
				cout << "                   :::TRIMOK:::                       " << endl;
				//e.mostrarTablero();
				play2();
				system("pause");
				break;

			case 3:
				cout << "Digite el Nick de el jugador blanco:" << endl;
				cin >> nickJugadorB;
				obtenerNick2(*jugadorBlanco, nickJugadorB);
				//cout << "El nombre es" << jugadorBlanco->darNick() << endl;
				play3();
				system("pause");
				break;

			case 4:
				play4();
				system("pause");

				break;

			default:
				break;
			}
		}
	} while (opcionParejas != 5);
}
void Trimok::mostrarDatos()
{
	//cout<<"Jugador Blanco"<<"\t";                                              cout<<"\tJugador Negro"<<endl;
	cout << "Jugador Blanco: " << jugadorBlanco->darNick() << "\t";
	cout << "\tJugador Negro: " << jugadorNegro->darNick();
}

void Trimok::obtenerNick()
{

	cout << "Digite el Nick de el jugador blanco: " << endl;
	cin >> nickJugadorB;
	nickJugadorB = jugadorBlanco->cambiarNick(nickJugadorB);
	cout << "Digite el Nick de el jugador Negro" << endl;
	cin >> nickJugadorN;
	nickJugadorN = jugadorNegro->cambiarNick(nickJugadorN);
}

void Trimok::obtenerNick2(JugadorHumano &j, string nombre)
{
	j.cambiarNick(nombre);
}
//void modificar();
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
				e.mostrarTablero();
				/*cout << "Puntaje " << jugadorBlanco->cambiarNick(nickJugadorB) << ":" << jugadorBlanco->darPuntaje() << endl;
				if (jugadorBlanco->darPuntaje() > 11)
				{
					cout << "Ganaste!!" << jugadorBlanco->darNick();
				}
				else if (jugadorBlanco->darPuntaje() > 11)
				{
					cout << "Ganaste!!" << jugadorBlanco->darNick();
				}*/
				cout << jugadorBlanco->darNick() << "--> "
					 << "Ingrese la Posicion actual" << endl;
				cin >> posActual;
				cout << jugadorBlanco->darNick() << "--> "
					 << "Ingrese la Posicion que desee mover" << endl;
				cin >> posNueva;
				bandera = jugadorBlanco->moverFicha(posNueva, posActual, 'B');
				//retorna verdadero si la regla se cumple
			}
		}
		bandera = false;
		while (bandera != true)
		{

			e.mostrarTablero();
			cout << "Puntaje " << jugadorNegro->darNick() << ":" << jugadorNegro->darPuntaje() << endl;
			cout << jugadorNegro->darNick() << "--> "
				 << "Ingrese la Posicion actual " << endl;
			cin >> posActual;
			cout << jugadorNegro->darNick() << "--> "
				 << "Ingrese la Posicion que desee mover" << endl;
			cin >> posNueva;
			bandera = jugadorNegro->moverFicha(posNueva, posActual, 'N');
		}
	}
}

int miRandom(int i, int f)
{
	return i + rand() % (f + 1);
}

void Trimok::play2()
{
	bool bandera;
	bool ganador = true;
	string posActual, posNueva;
	srand(time(NULL));
	int x[] = {0, 1, 2, 3, 4, 5};
	int temporal = 5;
	int temporal1;
	int tempora3;
	int temporal4;

	while (ganador)
	{
		bandera = false;
		//si bandera es diferente a verdadero entra al while
		while (bandera != true)
		{

			while (bandera != true)
			{

				for (int i = 0; i < 1; i++)
				{
					//temporal = x[miRandom(0, 5)];
					temporal1 = x[miRandom(0, 5)];
					tempora3 = x[miRandom(0, 1)];
					temporal4 = x[miRandom(0, 1)];
				}

				posActual = "";
				posNueva = "";
				//cout << "-" << temporal << endl;
				//cout << "*" << temporal << endl;
				posActual = to_string(temporal);
				posActual += to_string(temporal1);
				if ((temporal == 0) && (tempora3 == 1))
				{
					posNueva = to_string(temporal);
				}
				else
				{
					posNueva = to_string(temporal - tempora3);
				}
				/////////////
				//posNueva += to_string(temporal1 + temporal4);
				if ((temporal1 == 0) && (temporal4 == 1))
				{
					posNueva += to_string(temporal1);
				}
				else
				{
					posNueva += to_string(temporal1 - temporal4);
				}

				bandera = maquina->moverFicha(posNueva, posActual, 'B');
				temporal -= 1; //Recorre filas
				if (temporal < 0)
				{
					temporal = 5;
				}

				//cout << bandera << endl;
				//retorna verdadero si la regla se cumple
			}
		}
		bandera = false;
		while (bandera != true)
		{
			e.mostrarTablero();
			cout << "Puntaje " << jugadorNegro->darNick() << ":" << jugadorNegro->darPuntaje() << endl;
			cout << jugadorNegro->darNick() << "--> "
				 << "Ingrese la Posicion actual " << endl;
			cin >> posActual;
			cout << jugadorNegro->darNick() << "--> "
				 << "Ingrese la Posicion que desee mover" << endl;
			cin >> posNueva;
			bandera = jugadorNegro->moverFicha(posNueva, posActual, 'N');
			temporal = 5;
		}
	}
}

void Trimok::play3()
{
	bool bandera;
	bool ganador = true;
	string posActual, posNueva;
	srand(time(NULL));
	int x[] = {0, 1, 2, 3, 4, 5};
	int temporal;
	int temporal1;
	int tempora3;
	int temporal4;

	while (ganador)
	{
		bandera = false;
		//si bandera es diferente a verdadero entra al while
		while (bandera != true)
		{

			while (bandera != true)
			{

				e.mostrarTablero();
				cout << "Puntaje " << jugadorBlanco->darNick() << ":" << jugadorBlanco->darPuntaje() << endl;
				cout << jugadorBlanco->darNick() << "--> "
					 << "Ingrese la Posicion actual " << endl;
				cin >> posActual;
				cout << jugadorBlanco->darNick() << "--> "
					 << "Ingrese la Posicion que desee mover" << endl;
				cin >> posNueva;
				bandera = jugadorBlanco->moverFicha(posNueva, posActual, 'B');
				temporal = 0;

				//cout << bandera << endl;
				//retorna verdadero si la regla se cumple
			}
		}
		bandera = false;
		while (bandera != true)
		{
			for (int i = 0; i < 1; i++)
			{
				//temporal = x[miRandom(0, 5)];
				temporal1 = x[miRandom(0, 5)];
				tempora3 = x[miRandom(0, 1)];
				temporal4 = x[miRandom(0, 1)];
			}

			posActual = "";
			posNueva = "";
			//cout << "-" << temporal << endl;
			//cout << "*" << temporal << endl;
			posActual = to_string(temporal);
			posActual += to_string(temporal1);
			if ((temporal == 5) && (tempora3 == 1))
			{
				posNueva = to_string(temporal);
				//si se cumple , va enviar un 5
			}
			else
			{
				posNueva = to_string(temporal + tempora3);
			}
			/////////////
			//posNueva += to_string(temporal1 + temporal4);
			if ((temporal1 == 5) && (temporal4 == 1))
			{
				posNueva += to_string(temporal1);
				//se concatena
			}
			else
			{
				posNueva += to_string(temporal1 + temporal4);
			}

			bandera = maquina->moverFicha(posNueva, posActual, 'N');
			temporal += 1; //Recorre filas
			if (temporal > 5)
			{
				temporal = 0;
			}
		}
	}
}

void Trimok::play4()
{
	bool bandera;
	bool ganador = true;
	string posActual, posNueva;
	srand(time(NULL));
	int x[] = {0, 1, 2, 3, 4, 5};
	int maquinaN = 0;
	int maquinaB = 5;
	int temporal1;
	int tempora3;
	int temporal4;

	while (ganador)
	{
		bandera = false;
		//si bandera es diferente a verdadero entra al while
		while (bandera != true)
		{
			e.mostrarTablero();
			system("pause");
			playMaquina('B', 5);
			/*while (bandera != true)
			{

				
				maquinaN = 0;
				for (int i = 0; i < 1; i++)
				{
					//temporal = x[miRandom(0, 5)];
					temporal1 = x[miRandom(0, 5)];
					tempora3 = x[miRandom(0, 1)];
					temporal4 = x[miRandom(0, 1)];
				}

				posActual = "";
				posNueva = "";
				//cout << "-" << temporal << endl;
				//cout << "*" << temporal << endl;
				posActual = to_string(maquinaB);
				posActual += to_string(temporal1);
				if ((maquinaB == 0) && (tempora3 == 1))
				{
					posNueva = to_string(maquinaB);
				}
				else
				{
					posNueva = to_string(maquinaB - tempora3);
				}
				/////////////
				//posNueva += to_string(temporal1 + temporal4);
				if ((temporal1 == 0) && (temporal4 == 1))
				{
					posNueva += to_string(temporal1);
				}
				else
				{
					posNueva += to_string(temporal1 - temporal4);
				}

				bandera = maquina->moverFicha(posNueva, posActual, 'B');
				maquinaB -= 1; //Recorre filas
				if (maquinaB < 0)
				{
					maquinaB = 5;
				}

				//cout << bandera << endl;
				//retorna verdadero si la regla se cumple
			}*/
			bandera = false;
			e.mostrarTablero();
			system("pause");
			playMaquina('N', 0);
		}

		/*while (bandera != true)
		{

			playMaquina('N', 0);
			/*maquinaB = 5;
			for (int i = 0; i < 1; i++)
			{
				//temporal = x[miRandom(0, 5)];
				temporal1 = x[miRandom(0, 5)];
				tempora3 = x[miRandom(0, 1)];
				temporal4 = x[miRandom(0, 1)];
			}

			posActual = "";
			posNueva = "";
			//cout << "-" << temporal << endl;
			//cout << "*" << temporal << endl;
			posActual = to_string(maquinaN);
			posActual += to_string(temporal1);
			if ((maquinaN == 5) && (tempora3 == 1))
			{
				posNueva = to_string(maquinaN);
			}
			else
			{
				posNueva = to_string(maquinaN + tempora3);
			}
			/////////////
			//posNueva += to_string(temporal1 + temporal4);
			if ((temporal1 == 5) && (temporal4 == 1))
			{
				posNueva += to_string(temporal1);
			}
			else
			{
				posNueva += to_string(temporal1 + temporal4);
			}

			bandera = maquina->moverFicha(posNueva, posActual, 'N');
			maquinaN += 1; //Recorre filas
			if (maquinaN > 5)
			{
				maquinaN = 0;
			}
		}
		*/
	}
}

void Trimok::playMaquina(char color, int posicion)
{

	bool bandera;
	bool ganador = true;
	string posActual, posNueva;
	srand(time(NULL));
	int x[] = {0, 1, 2, 3, 4, 5};
	int maquinaB = 5;
	int temporal1;
	int tempora3;
	int temporal4;

	while (bandera != true)
	{
		int maquinaBN = posicion;
		for (int i = 0; i < 1; i++)
		{
			//temporal = x[miRandom(0, 5)];
			temporal1 = x[miRandom(0, 5)];
			tempora3 = x[miRandom(0, 1)];
			temporal4 = x[miRandom(0, 1)];
		}

		posActual = "";
		posNueva = "";
		//cout << "-" << temporal << endl;
		//cout << "*" << temporal << endl;
		posActual = to_string(maquinaBN);
		posActual += to_string(temporal1);
		if ((maquinaB == (5 - posicion)) && (tempora3 == 1))
		{
			posNueva = to_string(maquinaBN);
		}
		else
		{
			if (posicion == 0)
			{
				posNueva = to_string(maquinaBN + tempora3);
			}
			if (posicion == 5)
			{
				posNueva = to_string(maquinaBN - tempora3);
			}

			//posNueva = to_string(maquinaBN - tempora3);
		}
		/////////////
		//posNueva += to_string(temporal1 + temporal4);
		if ((temporal1 == (5 - posicion)) && (temporal4 == 1))
		{
			posNueva += to_string(temporal1);
		}
		else
		{
			//posNueva += to_string(temporal1 - temporal4);
			if (posicion == 0)
			{
				posNueva += to_string(temporal1 + temporal4);
			}
			if (posicion == 5)
			{
				posNueva += to_string(temporal1 - temporal4);
			}
		}
		//char blanco[] = "B";
		bandera = maquina->moverFicha(posNueva, posActual, color);
		if (color == 'B')
		{
			maquinaBN -= 1; //Recorre filas
			if (maquinaBN < 0)
			{
				maquinaBN = 5;
			}
		}

		if (color == 'N')
		{
			maquinaBN += 1; //Recorre filas
			if (maquinaBN > 5)
			{
				maquinaBN = 0;
			}
		}
	}
}