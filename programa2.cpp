#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;
int cantidad;

struct Persona {
    string nombre;
    char fecha[11];
    int tamanio_tarjeta;
    int* tarjeta;
    bool quiere_intercambiar;
};
/*
4
Pepito 1999-01-12 1
Juanito 2000-12-10 0
sinnombre 2012-20-01 1
puntoycoma 2012-20-20 0
*/

int* comprarTarjeta(string nombre, int dia, int &m){
    m = nombre.length();
    int* ficha = new int[m];
    for (int i = 0; i < m; i++){
        ficha[i] = (int) nombre[i] % dia;
        //cout << ficha[i]<< "\n";
    }
    return ficha;
}
void intercambiarTarjeta(Persona*p1, Persona*p2){
    int* swap = p1->tarjeta;
    p1->tarjeta = p2->tarjeta;
    p2->tarjeta = swap;
    p1->quiere_intercambiar = 0;
}

int puntaje(Persona* p1){
    int contador,numero;
    for(int i=0;i<p1->tamanio_tarjeta-1;i++){
        numero=p1->tarjeta[i]*p1->fecha[i%10];
        contador+=numero;
    }
    return contador;
}

Persona* unDia(Persona* personas,int dia){
    for(int i=0;i<cantidad;i++){
        
    }
    
}

int main(){
    int m;
    //int dias = 2;
    int *ficha;
    cin>> cantidad;
    Persona per[cantidad];
    for (int i=0; i<cantidad; i++){ 
        cin >> per[i].nombre >> per[i].fecha >> per[i]. quiere_intercambiar;
    }
    for (int i=0; i<cantidad; i++){
        ficha = comprarTarjeta(per[i].nombre, 2, m);
        per[i].tarjeta = ficha;
        delete[] ficha;
    }
    for (int i=0; i<cantidad; i++){
        if (per[i].quiere_intercambiar != 0){
            for (int j = i + 1; j < cantidad; j++){
                if (per[j].quiere_intercambiar != 0){
                    intercambiarTarjeta(&per[i], &per[j]);
                    break;
                }
            }
        }
    }
    return 0;
}
/* 
Demuestra que es el arreglo correspondiente
    for (int j= 0; j < 7;j++){
        cout << (per[i].tarjeta)[j] << " ";
    }
    cout<<"\n";
*/