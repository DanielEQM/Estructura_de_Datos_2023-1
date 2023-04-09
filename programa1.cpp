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
};

int main(){
    int n;
    string i;
    std::ifstream file;
    file.open("saldos.bin", ios::in|ios::binary);
    if(!file.is_open()){
		cout << "ERROR, no hay ningun archivo abierto." << endl;
		exit(1);
    }
    file.read((char*)&n, sizeof(int));
    file.seekg(1);
    for(int m=0; m<(n);m++){
        getline(file,i);
        cout << i << endl;
    }
    file.close();
    return 0;
};

// matigod