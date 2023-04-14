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

int* comprarTarjeta(string nombre, int dia, int &m){
    m = nombre.length();
    int* ficha = new int[m];
    for (int i = 0; i < m; i++){
        ficha[i] = (int) nombre[i] % dia;
    }
    return ficha;
}

void intercambiarTarjeta(Persona*p1, Persona*p2){
    int* swap = p1->tarjeta;
    int swap2 = p1->tamanio_tarjeta;
    p1->tamanio_tarjeta = p2->tamanio_tarjeta;
    p2->tamanio_tarjeta = swap2;
    p1->tarjeta = p2->tarjeta;
    p2->tarjeta = swap;
    p1->quiere_intercambiar = 0;
}


int puntaje(Persona* p1){
    int contador = 0,numero;
    for(int i=0;i<p1->tamanio_tarjeta;i++){
        numero= p1->tarjeta[i] * ((int) p1->fecha[i%10]);
        contador+=numero;
    }
    return contador;
}

bool comun(Persona *p1, Persona *p2){
    int a = (p1->nombre).length();
    int b = (p2->nombre).length();
    for (int i=0; i< a;i++){
        for (int j = 0; j < b; j++){
            if (p1->tarjeta[i] == p2->tarjeta[j]){
                return 1;
            }
        }
    }
    return 0;
}

Persona* unDia(Persona* personas,int dia){
    int m;
    bool X;
    int menor = -1;
    int puntos;
    int win;
    for (int i=0; i<cantidad; i++){
        personas[i].tarjeta = comprarTarjeta(personas[i].nombre, dia, m);
        personas[i].tamanio_tarjeta = m;
    }
    for (int i=0; i<cantidad; i++){
        if (personas[i].quiere_intercambiar != 0){
            for (int j = i + 1; j < cantidad; j++){
                if (personas[j].quiere_intercambiar != 0){
                    X = comun(&personas[i], &personas[j]);
                    if (X == 1){    
                        intercambiarTarjeta(&personas[i], &personas[j]);
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i<cantidad; i++){
        puntos = puntaje(&personas[i]);
        if(menor < puntos){
            menor = puntos;
            win = i;
        }
    }
    return &personas[win];
}

void variosDias(Persona* personas, int cant_dias){
    Persona *pers;
    for(int i= 1; i < cant_dias + 1; i++){
        pers = unDia(personas, i);
        int score = puntaje(pers);
        cout<<pers->nombre << " " << pers->fecha << " " << score << "\n";
        for (int i = 0; i <cantidad; i++){
            delete[] personas[i].tarjeta;
        }
    }
}

int main(){
    cin>> cantidad;
    Persona per[cantidad];
    for (int i=0; i<cantidad; i++){ 
        cin >> per[i].nombre >> per[i].fecha >> per[i]. quiere_intercambiar;
    }
    variosDias(per, 2);
    return 0;
}