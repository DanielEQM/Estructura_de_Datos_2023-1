#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int const SERV_DESAYUNO = 0;
int const SERV_ALMUERZO = 1;
int const SERV_ONCE = 2;
int const SERV_CENA = 3;

struct SaldoColaborador {
    char rut[11] ;
    int saldo_desayuno ;
    int saldo_almuerzo ;
    int saldo_once ;
    int saldo_cena ;
};

bool puedeConsumir(char* rut, int servicio, string consumos_dia){
    fstream file;
    int i = 0;
    string line;
    ifstream bin;
    int n;
    int saldo;
    bool revision = false;
    bin.open("saldos.bin", ios::binary);
    if (!bin.is_open()){
        cerr << "Error al abrir el archivo" << "\n";
        cout << "sexo1" << "\n";
        exit(1);
    }
    bin.read((char*)&n, sizeof(n));
    SaldoColaborador* arr = new SaldoColaborador[n];
    bin.read((char*)arr, sizeof(SaldoColaborador)*n);
    bin.close();
    file.open(consumos_dia, ios::in);
    if (!file.is_open()){
        cerr << "Error al abrir el archivo" << "\n";
        cout << "sexo2" << "\n";
        exit(1);
    }
    while(!file.eof()){
        getline(file, line);
        i++;
    }
    file.close();
    string mosquito = rut;
    for(int m=0; m<n; m++){
        string rgb = arr[m].rut;
        if(rgb == mosquito){
            revision = true;
            if(servicio == SERV_DESAYUNO){
                saldo = arr[m].saldo_desayuno;
            }
            else if (servicio == SERV_ALMUERZO){
                saldo = arr[m].saldo_almuerzo;
            }
            else if (servicio == SERV_ONCE){
                saldo = arr[m].saldo_once;
            }
            else if (servicio == SERV_CENA){
                saldo = arr[m].saldo_cena;
            }
        }
    }
    cout << rut << "\n";
    if (revision == false){
        return 0;
    }
    file.open(consumos_dia, ios::in);
    if (!file.is_open()){
        cerr << "Error al abrir el archivo" << "\n";
        cout << "sexo3" << "\n";
        exit(1);
    }
    file.seekg(0);
    string x;
    string comida;
    string quiere;
    int gasto = 0;
    for(int j = 0; j < i; j++){
        file >> x >> comida;
        if(x == mosquito){
            if (comida == "DESAYUNO"){
                if(SERV_DESAYUNO == servicio){
                    gasto++;
                    quiere = comida;
                }
            }
            else if (comida == "ALMUERZO"){
                if(SERV_ALMUERZO == servicio){
                    gasto++;
                    quiere = comida;
                }
            }
            else if (comida == "ONCE"){
                if(SERV_ONCE == servicio){
                    gasto++;
                    quiere = comida;
                }
            }
            else if (comida == "CENA"){
                if(SERV_CENA == servicio){
                    gasto++;
                    quiere = comida;
                }
            }
        }
    }
    file.close();
    if (gasto >= saldo){
        return 0;
    }
    file.open(consumos_dia, ios::app);
    if (!file.is_open()){
        cerr << "Error al abrir el archivo" << "\n";
        cout << "sexo4" << "\n";
        exit(1);
    }
    file << "\n" << rut << " " << quiere;
    return 1;
}



int main(){
    char f[11] = "11111111-1";
    cout << puedeConsumir(f, SERV_ALMUERZO, "consumosD.txt") <<"\n";
    return 0;
}

// matigod