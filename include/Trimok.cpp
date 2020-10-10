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
string nickJugadorB; //Se guarda el nombre de jugador Blanco
string nickJugadorN; //Se guarda el nombre de jugador Negro

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
				cout << "Para mover ficha ingresa la letra mayuscula y un numero " << endl;
				cout << "Solo se puede mover una posicion" << endl;
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
				break;
			}
			system("cls");
		}

	} while (opcion != 3);
}
void Trimok::seleccionarParejas()
{

	cout << "  Modo de Juego  " << endl;
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
	ganadorDelJuego->crearArchivo();
	do
	{
		seleccionarParejas();

		{
			switch (opcionParejas)
			{
			case 1:
				jugadorBlanco = fabrica->darHumano();
				jugadorNegro = fabrica->darHumano();
				obtenerNick();
				mostrarDatos();
				e.inicializarTablero();
				cout << "                   :::TRIMOK:::                       " << endl;
				play();
				system("pause");
				//destructor();
				break;

			case 2:
				maquina = fabrica->darMaquina();
				jugadorNegro = fabrica->darHumano();
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
				jugadorBlanco = fabrica->darHumano();
				maquina = fabrica->darMaquina();
				cout << "Digite el Nick de el jugador blanco:" << endl;
				cin >> nickJugadorB;
				obtenerNick2(*jugadorBlanco, nickJugadorB);
				//cout << "El nombre es" << jugadorBlanco->darNick() << endl;
				play3();
				system("pause");
				break;

			case 4:
				maquina = fabrica->darMaquina();
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
	jugadorBlanco->cambiarNick(nickJugadorB);
	cout << "Digite el Nick de el jugador Negro" << endl;
	cin >> nickJugadorN;
	jugadorNegro->cambiarNick(nickJugadorN);
}
void Trimok::obtenerNick2(JugadorHumano &j, string nombre)
{
	j.cambiarNick(nombre);
}
void Trimok::play()
{
	bool bandera;
	bool ganador = true;
	string posActual, posNueva;
	bool salir = false;
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
					 << "Ingrese la Posicion actual" << endl;
				cin >> posActual;
				cout << jugadorBlanco->darNick() << "--> "
					 << "Ingrese la Posicion que desee mover" << endl;
				cin >> posNueva;
				//jugadorBlanco->poderRetornar('B', jugadorNegro->darPuntaje()); /RETORNO
				bandera = jugadorBlanco->moverFicha(posNueva, posActual, 'B');
				if (jugadorBlanco->darPuntaje() >= 6)
				{
					char opcionLetra;
					while (!salir)
					{
						cout << jugadorBlanco->darNick() << "-->"
							 << " Desea volver al Menu (S/N)" << endl;
						cin >> opcionLetra;
						if (tolower(opcionLetra) == 's')
						{
							bandera = true;
							ganador = false;
							salir = true;
							e.inicializarTablero();
							ganadorDelJuego->setNombre(jugadorNegro->darNick());
							ganadorDelJuego->setPuntaje(jugadorNegro->darPuntaje());
							ganadorDelJuego->guardarDatos();
						}
						else
						{
							if (tolower(opcionLetra) == 'n')
							{
								break;
							}
						}
					}
					if (!salir)
					{
						cout << "Puede seguir Jugando" << endl;
					}
				}
				//retorna verdadero si la regla se cumple
			}
		}
		if (!salir)
		{
			bandera = false;
		}
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
			//jugadorNegro->poderRetornar('N', jugadorBlanco->darPuntaje()); /RETORNO
			bandera = jugadorNegro->moverFicha(posNueva, posActual, 'N');
			if (jugadorNegro->darPuntaje() >= 6)
			{
				char opcionLetra;
				while (!salir)
				{
					cout << jugadorNegro->darNick() << "-->"
						 << "Desea volver al menu (S/N)" << endl;
					cin >> opcionLetra;
					if (tolower(opcionLetra) == 's')
					{
						bandera = true;
						ganador = false;
						salir = true;
						ganadorDelJuego->setNombre(jugadorBlanco->darNick());
						ganadorDelJuego->setPuntaje(jugadorBlanco->darPuntaje());
						ganadorDelJuego->guardarDatos();
					}
					else
					{
						if (tolower(opcionLetra) == 'n')
						{
							break;
						}
					}
				}
				if (!salir)
				{

					cout << "Puede seguir Jugando" << endl;
				}
			}
		}
		if (jugadorBlanco->darPuntaje() == 11)
		{
			cout << jugadorBlanco->darNick() << ": "
				 << "Es El Ganador" << endl;
			ganadorDelJuego->setNombre(jugadorBlanco->darNick());
			ganadorDelJuego->setPuntaje(jugadorBlanco->darPuntaje());
			ganadorDelJuego->guardarDatos();
			ganador = false;
		}
		if (jugadorNegro->darPuntaje() == 12)
		{
			cout << jugadorNegro->darNick() << ": "
				 << "Es El Ganador" << endl;
			ganadorDelJuego->setNombre(jugadorNegro->darNick());
			ganadorDelJuego->setPuntaje(jugadorNegro->darPuntaje());
			ganadorDelJuego->guardarDatos();
			ganador = false;
		}
	}
}

int miRandom(int i, int f)
{
	return i + rand() % (f + 1); //Funcion Para Maquina Vs Jugador o Viceversa
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
					temporal1 = x[miRandom(0, 5)];
					tempora3 = x[miRandom(0, 1)];
					temporal4 = x[miRandom(0, 1)];
				}

				posActual = "";
				posNueva = "";
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
		if (maquina->darPuntaje() == 12)
		{
			ganadorDelJuego->setNombre(maquina->darNick());
			ganadorDelJuego->setPuntaje(maquina->darPuntaje());
			ganadorDelJuego->guardarDatos();
			ganador = false;
		}
		if (jugadorNegro->darPuntaje() == 12)
		{
			ganadorDelJuego->setNombre(jugadorNegro->darNick());
			ganadorDelJuego->setPuntaje(jugadorNegro->darPuntaje());
			ganadorDelJuego->guardarDatos();
			ganador = false;
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
		if (jugadorBlanco->darPuntaje() == 12)
		{
			ganadorDelJuego->setNombre(jugadorBlanco->darNick());
			ganadorDelJuego->setPuntaje(jugadorBlanco->darPuntaje());
			ganadorDelJuego->guardarDatos();
			ganador = false;
		}
		if (maquina->darPuntaje() == 12)
		{
			ganadorDelJuego->setNombre(maquina->darNick());
			ganadorDelJuego->setPuntaje(maquina->darPuntaje());
			ganadorDelJuego->guardarDatos();
			ganador = false;
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
			playMaquina1('B', 5);

			bandera = false;
			e.mostrarTablero();
			system("pause");
			playMaquina1('N', 0);
		}
		if (maquina->darPuntaje() == 12)
		{
			ganadorDelJuego->setNombre(maquina->darNick());
			ganadorDelJuego->setPuntaje(maquina->darPuntaje());
			ganadorDelJuego->guardarDatos();
			ganador = false;
		}
	}
}

void Trimok::playMaquina(char color, int posicion)
{

	bool bandera = false;
	bool ganador = true;
	string posActual, posNueva;
	srand(time(NULL));
	int x[] = {0, 1, 2, 3, 4, 5};
	int maquinaB = 5;
	int temporal1;
	int tempora3;
	int temporal4;

	int maquinaBN = posicion;
	while (bandera != true)
	{
		for (int i = 0; i < 1; i++)
		{
			//temporal = x[miRandom(0, 5)];
			temporal1 = x[miRandom(0, 5)];
			tempora3 = x[miRandom(0, 1)];
			temporal4 = x[miRandom(0, 1)];
		}
		//cout << "[ "<<maquinaBN<<"]"<< temporal1<< endl;

		posActual = "";
		posNueva = "";
		//cout << "-" << temporal << endl;
		//cout << "*" << temporal << endl;
		cout << "maquina BN" << maquinaBN << endl;
		posActual = to_string(maquinaBN);
		posActual += to_string(temporal1);
		if ((maquinaBN == (5 - posicion)) && (tempora3 == 1))
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
		}
		/////////////
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
		//cout<<"Actual"<<posActual<<endl;
		//cout<<"Nueva"<<posNueva<<endl;
		bandera = maquina->moverFicha(posNueva, posActual, color);
		//system("pause");
		if (color == 'B')
		{
			maquinaBN -= 1;
			//cout<<"Contador"<<maquinaBN<<endl; //Recorre filas
			if (maquinaBN < 0)
			{
				maquinaBN = 5;
			}
		}

		if (color == 'N')
		{
			maquinaBN += 1;
			//Recorre filas
			if (maquinaBN > 5)
			{
				maquinaBN = 0;
			}
		}
	}
}

int miRandom2(int i, int f)
{
	return i + rand() % f;
}
void Trimok::playMaquina1(char color, int posicion)
{

	bool bandera = false;
	string posActual, posNueva;
	srand(time(NULL));
	int columnaActual[] = {-1, 0, 1, 2, 3, 4, 5};
	int posicionCol[] = {-1, 1};
	int posicionFil[] = {-1, 0, 1};
	int colPosicionActual;
	int tmpFilaNueva;
	int tmpColumnaNueva;
	int maquinaBN = posicion;
	while (bandera != true)
	{
		for (int i = 0; i < 1; i++)
		{
			colPosicionActual = columnaActual[miRandom2(1, 6)]; //posicion Actual es 5

			if (color == 'B') //MaquinABN = 0
			{
				tmpFilaNueva = columnaActual[miRandom2(0, 1)];
				if (tmpFilaNueva == 0)
				{
					tmpColumnaNueva = posicionCol[miRandom2(0, 1)];
				}
				if (tmpFilaNueva == -1)
				{
					tmpColumnaNueva = posicionFil[miRandom2(0, 2)];
				}
			}

			//Negro
			if (color == 'N')
			{
				tmpFilaNueva = columnaActual[miRandom2(1, 2)];
				if (tmpFilaNueva == 0)
				{
					tmpColumnaNueva = posicionCol[miRandom2(0, 1)];
				}
				if (tmpFilaNueva == -1)
				{
					tmpColumnaNueva = posicionFil[miRandom2(0, 2)];
				}
			}
		}
		if ((colPosicionActual + tmpFilaNueva) < 0)
		{
			colPosicionActual = 0;
			tmpFilaNueva = 0;
		}
		if ((maquinaBN + tmpColumnaNueva) < 0)
		{
			maquinaBN = 0;
			tmpColumnaNueva = 0;
		}
		if ((colPosicionActual + tmpFilaNueva) > 5)
		{
			colPosicionActual = 5;
			tmpFilaNueva = 0;
		}
		if ((maquinaBN + tmpColumnaNueva) > 5)
		{
			maquinaBN = 5;
			tmpColumnaNueva = 0;
		}

		posActual = "";
		posNueva = "";
		posActual = to_string(maquinaBN) + to_string(colPosicionActual);
		posNueva = to_string(colPosicionActual + tmpFilaNueva) + to_string(maquinaBN + tmpColumnaNueva);
		//cout << "Actual: " << posActual << endl;
		//cout << "Nueva: " << posNueva << endl;

		bandera = maquina->moverFicha(posNueva, posActual, color);

		if (color == 'B')
		{
			maquinaBN -= 1;

			if (maquinaBN < 0)
			{
				maquinaBN = 5;
			}
		}

		if (color == 'N')
		{
			maquinaBN += 1;
			//Recorre filas
			if (maquinaBN > 5)
			{
				maquinaBN = 0;
			}
		}
	}
}