#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

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
//void intercambiarTarjeta(Persona*p1, Persona*p2){}

int main(){
    int m;
    int cantidad;
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
    return 0;
}
/* 
Demuestra que es el arreglo correspondiente
    for (int j= 0; j < 7;j++){
        cout << (per[i].tarjeta)[j] << " ";
    }
    cout<<"\n";
*/