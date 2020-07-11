#ifndef __CLASSFICHA
#define __CLASSFICHA

class Ficha
{
private:
    std::string blanco;
    std::string negro;
public:
    Ficha();
    void colorFicha(string blanco,string negro);
    int cantidadDeFichas(Ficha);
    char darFicha(int colorFicha,int posiciones, int cantidadDeFichas);
    ~Ficha();
};

Ficha::Ficha(/* args */)
{
}

Ficha::~Ficha()
{
}


#endif // __CLASFICHA