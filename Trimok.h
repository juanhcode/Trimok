class Trimok
{
private:
    int opcion;
    int puntaje;
public:
    Trimok();
    int mostrarMenu();
    int  cambiarPuntaje (int puntaje, int tablero);
    void visualizarMarcador (int puntajeFichaNegra, int puntajeFichaBlanca);
    int obtenerJugadores(int jugador1, int jugador2);
    bool salir();
    
    ~Trimok();
};

Trimok::Trimok()
{
}

Trimok::~Trimok()
{
}
