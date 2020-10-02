#include <iostream>
using namespace std;
class Ganadores
{
private:
    string nombre;
    int puntaje;
public:
    Ganadores();
    ~Ganadores();
    void crearArchivo();
    void guardarDatos();
    void setPuntaje(int nuevoPuntaje);
    void setNombre(string nuevoNombre);

};
