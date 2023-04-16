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
    file.open("consumosD.txt", ios::in);
    if (!file.is_open()){
        cerr << "Error al abrir el archivo" << "\n";
        exit(1);
    }
    string line;
    int i = 0;
    while(!file.eof()){
        getline(file, line);
        cout << line << "\n";
        i++;
    }
    file.close();
    ifstream bin;
    bin.open("saldos.bin", ios::binary);
    if (!bin.is_open()){
        cerr << "Error al abrir el archivo" << "\n";
        exit(1);
    }
    cout << "xd" << "\n";
    int n;
    int saldo;
    bool revision = false;
    bin.read((char*)&n, sizeof(n));
    SaldoColaborador* arr = new SaldoColaborador[n];
    bin.read((char*)arr, sizeof(SaldoColaborador)*n);
    for(int m=0; m<n; m++){
        if(arr[m].rut == rut){
            revision = true;
            if(servicio == 0){
                saldo = arr[m].saldo_desayuno;
            }
            else if (servicio == 1){
                saldo = arr[m].saldo_almuerzo;
            }
            else if (servicio == 2){
                saldo = arr[m].saldo_once;
            }
            else if (servicio == 3){
                saldo = arr[m].saldo_cena;
            }
        }
    }
    if (revision == false){
        cout << "sexo2" << "\n";
        return 0;
    }
    file.open("consumosD.txt", ios::in);
    if (!file.is_open()){
        cerr << "Error al abrir el archivo" << "\n";
        exit(1);
    }
    file.seekg(0);
    char x[11];
    string comida;
    string quiere;
    int gasto = 0;
    for(int j = 0; j < i; j++){
        file >> x >> comida;
        if(x == rut){
            if (comida == "DESAYUNO"){
                int comida2 = 0;
                if(comida2 == servicio){
                    gasto++;
                    quiere = comida;
                }
            }
            if (comida == "ALMUERZO"){
                int comida2 = 1;
                if(comida2 == servicio){
                    gasto++;
                    quiere = comida;
                }
            }
            if (comida == "ONCE"){
                int comida2 = 2;
                if(comida2 == servicio){
                    gasto++;
                    quiere = comida;
                }
            }
            if (comida == "CENA"){
                int comida2 = 3;
                if(comida2 == servicio){
                    gasto++;
                    quiere = comida;
                }
            }
        }
    }
    if (gasto >= saldo){
        cout << "sexo" << "\n";
        return 0;
    }
    file.close();
    file.open("consumosD.txt", ios::out);
    if (!file.is_open()){
        cerr << "Error al abrir el archivo" << "\n";
        exit(1);
    }
    file.seekg(0, ios::end);
    file << rut << " " << quiere << "\n";
    return 1;
    }



int main(){
    bool marica;
    marica = puedeConsumir("11111111-1", SERV_DESAYUNO, "consumosD.txt");
    return 0;
}

// matigod