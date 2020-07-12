#include <iostream>

#include "Tablero.h"

int Tablero::crearTablero(){
    int tablero[6][6];

    //imprimir tablero
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            tablero[i][j] = 0;
            std::cout<<tablero[i][j]<<"|"<<std::endl;
        }
        std::cout<<"\n"<<std::endl;
        
    }  
}

int Tablero::cambiarPuntaje(int puntaje){   
}