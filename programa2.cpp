#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Persona {
    string nombre ;
    char fecha [11];
    int tamanio_tarjeta ;
    int * tarjeta ;
    bool quiere_intercambiar ;
};

int*comprarTarjeta(string nombre, int dia, int &m){
    int arreglo[m];
    for(int i=0;i<m;i++){
        arreglo[i] //hay que hacer que cada elemento del arreglo sea una letra ASCII
    } // y a lo de arriba hay que hacerle modulo (%) por el dia.
    return arreglo;
}

void intercambiarTarjeta(Persona*p1, Persona*p2){

}