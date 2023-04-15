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
    return 0;
}

int main(){
    ifstream fp;
    int n;
    fp.open("saldos.bin", ios::binary);
    if (!fp.is_open()){
        cerr << "Error el abrir el archivo" << "\n";
        return 1;
    }
    fp.read((char*)&n, sizeof(int));
    SaldoColaborador* arr = new SaldoColaborador[n];
    fp.read((char*)arr, sizeof(SaldoColaborador) * n);
    for (int i = 0; i < n; i++){
        cout << arr[i].rut << " " << arr[i].saldo_almuerzo << " " << arr[i].saldo_cena << " " << arr[i].saldo_desayuno << " " << arr[i].saldo_once << "\n";
    }
    fp.close();
    return 0;
}

// matigod