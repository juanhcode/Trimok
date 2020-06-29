#include <iostream>
using namespace std;


int main(){
    int opcion;

    cout<<"                      JUEGO TRIMOK          "<<endl;
    cout<<"1.Jugar"<<endl;
    cout<<"2.Salir"<<endl;
    cout<<"Escoger una opcion:  "<<endl;
    cin>>opcion;


    switch (opcion)
    {
    case 1:
    char opcion2;
        cout<<"Que Pareja de jugador quieres Escojer"<<endl;
        cout<<"(S) Jugador Blanco // Jugador Negro"<<endl;
        cout<<"(N) Jugador Negro // Jugador Blanco"<<endl;
        cin>>opcion2;

        switch (opcion2)
        {
        case 'S':
            cout<<"Jugador Blanco"<<endl;
            cout<<"Fichas Disponibles:12 "<<endl;

            cout<<"Jugador Negro"<<endl;
            cout<<"Fichas Disponibles:12 "<<endl;
            char matriz[6][6];

            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                if (i==0 or i==4)
                    matriz[i][j]= '*';
                if(j== 0 or j==4)
                    matriz[i][j]='>';
                }
            }  
//imprimir
            for ( int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    cout<<matriz[i][j]<<"   ";
                }
                cout<<endl;
            }
            break;

            case 'N':
                cout<<"Fichas Disponibles"<<endl;

            default:
                cout<<"Opcion Invalida"<<endl;
                break;
        }

    }
}
    
