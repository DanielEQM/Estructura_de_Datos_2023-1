#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int const SERV_DESAYUNO = 0;
int const SERV_ALMUERZO = 1;
int const SERV_ONCE = 2;
int const SERV_CENA = 3;

struct SaldoColaborador {
    string rut ;
    int saldo_desayuno ;
    int saldo_almuerzo ;
    int saldo_once ;
    int saldo_cena ;
};

bool puedeConsumir(char* rut, int servicio, string consumos_dia){
    return 0;
};

int main(){
    int n;
    std::ifstream file;
    file.open("saldos.bin", ios::binary);
    file.read((char*)&n, sizeof(int));
    cout << n << "xd" << endl;
    file.close();
};

// matigod