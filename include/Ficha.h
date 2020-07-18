#ifndef __CLASSFICHA
#define __CLASSFICHA
using namespace std;
#include <string>

class Ficha
{
private:
	string blanco;
	string negro;
    int Posx;
    int Posy; 
    int tipo;
    int color;
    int Piedra;
    int Papel;
    int Tijera;

public:
    Ficha();
    Fichas(int color, int tipo, int Posy, int Posx);
    int darColor(string blanco,string negro);
    int darTipo();
    int darPosicionY();
    int darPosicionX();
    bool unEspacioVacion();
    bool puedeMoverse();
    int puedeComerUnaFicha();
    int retornoHabilitado();
    void cambiarTipo();
   
    ~Ficha();

};

Ficha::Ficha(/* args */)
{
}

Ficha::~Ficha()
{
}


#endif // __CLASFICHA