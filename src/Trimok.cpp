#include "./Trimok.h"
#include <iostream>
using namespace std;

void auxiliar();
void Trimok::mostrarMenu(){
    cout<<endl;
    cout<<"                         TRIMOK                     "<<endl;
	cout<<"1- Instrucciones"<< endl;
	cout<<"2 - Jugar" << endl;
	cout<<"3 - Salir" << endl;
	do
	{
		cout<<"Introduza Opcion: ";
		cin >> opcion;		
	}while(!((opcion>=1) && (opcion<=3)));
}

void Trimok::visualizar(){
    
    do
    {
        switch (opcion)
        {
        case 1:
            cout<<"Reglas"<<endl;
            cout<<"           FICHAS BLANCAS:                    "<<endl;
            cout<<"tijeras blancas toman el papel negro"<<endl;
            cout<<"papel blanco toma la roca negra"<<endl;
            cout<<"roca blanca  toman tijeras negras"<<endl;
            cout<<endl;
            cout<<"                    FICHAS NEGRAS:            "<<endl;
            cout<<"tijeras negras toman el papel blanco"<<endl;
            cout<<"papel negro toma la roca blanca"<<endl;
            cout<<"roca negra toman tijeras blancas"<<endl;
            break;
        case 2:
            auxiliar();
            break;
        case 3:
            /* code */
            break;

        default:
            break;
        }
    } while (opcion!=3);
    
}

void auxiliar(){

    int opcion;
    cout<<"Escoger Jugador"<<endl;
    cout<<"1-Jugador Blanco"<<endl;
    cout<<"2-Jugador Negro"<<endl;
    cin>>opcion;
    
    do
    {
        switch (opcion)
        {
        case 1:

            break;
        case 2:
        
            break;
        default:
            break;
        }
    } while (opcion!=2);
    
}