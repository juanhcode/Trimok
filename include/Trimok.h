/*Nombre de archivo: Trimok.h
Version: 0.1
Fecha de creacion: 29/06/2020
Fecha de ultima de moficacion: 29/06/2020
Autor: Juan Manuel Hoyos Contreras - 201958950-2711
     : Luis alberto alegria riascos -201958640-2711
     : Emanuel benjumea bejarano - 201958941-2711
     : cesar augusto gallego niño 1958553-2711
     : Steven Vargas González 1958675-2711
Correos electronicos: juan.manuel.hoyos@correounivalle.edu.co
                    : vargas.steven@correounivalle.edu.co
                    : Emanuel.benjumea@correounivalle.edu.co
                    : gallego.cesar@correounivalle.edu.co
                    : Lui.alegria@correounivalle.edu.co
/*CRC:
Clase: Trimok
Responsabilidad:
-cambiar puntahe 
-visualizar marcador
-obtener jugadores
-salir
Colaboracion: tablero
*/
#ifndef __CLASSTRIMOK
#define __CLASSTRIMOK
#include "Ficha.h"
#include "Tablero.h"
#include "JugadorHumano.h"
#include "JugadorComputadorAlAzar.h"
class Trimok
{
private:
    int opcion;
    int opcionParaEljugador;
    int opcionParejas;
    Tablero e;
    JugadorHumano *jugadorBlanco = new JugadorHumano();
    JugadorHumano *jugadorNegro = new JugadorHumano();
    JugadorComputadorAlAzar *maquina = new JugadorComputadorAlAzar();


public:
    Trimok();
    ~Trimok();
    void seleccionarOpcion();
    void visualizar();
    void mostrarDatos();
    void obtenerNick();
    void play();
    void play2();
    void play3();
    void play4();
    void playMaquina(char color,int posicion);
    //Metodos aun sin utilizar
    void seleccionJugador();
    void escogerJugador();
    int cambiarPuntaje(int puntaje, int tablero);
    void visualizarMarcador(int puntajeFichaNegra, int puntajeFichaBlanca);
    int obtenerJugadores(int jugador1, int jugador2);
    //int empezarJuego(Tablero Tablerito, Jugador Jugador1, Jugador Jugador2, Ficha FichaN, Ficha FichaB);
    bool salir();
    void seleccionarParejas();
    void visualizarParejas();
    void obtenerNick2(JugadorHumano &j,string  nombre);
};
#endif // __CLASTRIMOK



