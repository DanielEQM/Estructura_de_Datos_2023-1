#include <iostream>
#include <string>

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

// hola