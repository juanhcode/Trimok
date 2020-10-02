#include "Ganadores.h"
#include <iostream>
using namespace std;
#include <fstream>

Ganadores::Ganadores()
{
    crearArchivo();
}

Ganadores::~Ganadores()
{
}

void Ganadores::crearArchivo()
{
    ofstream archivo;
    archivo.open("Ganadores.txt", ios::app);
    if (archivo.fail())
    {
        cout << "No se puede crear el archivo" << endl;
        exit(1);
    }
    archivo.close();
}

void Ganadores::setNombre(string nuevoNombre)
{
    nombre = nuevoNombre;
}

void Ganadores::setPuntaje(int nuevoPuntaje)
{
    puntaje = nuevoPuntaje;
}

void Ganadores::guardarDatos()
{
    ofstream archivo;
    archivo.open("Ganadores.txt", ios::app);
    if (archivo.fail())
    {
        cout << "No se puede crear el archivo" << endl;
        exit(1);
    }
    archivo<<"Nombre: "<<nombre<<"          Puntaje: "<<puntaje<<endl;
    archivo.close();
}
