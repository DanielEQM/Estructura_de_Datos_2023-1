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

/*struct comparacion {
    char rutC[11] ;
    string comida;
};
*/
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
    cout << i << "\n";
    file.seekg(0);
    char x[11];
    string comida;
    for(int j = 0; j < i; j++){
        file >> x >> comida;
        cout << x << " " << comida << "\n";
    }
    return 0;
    }



int main(){
    ifstream fp;
    int n;
    bool marica;
    fp.open("saldos.bin", ios::binary);
    if (!fp.is_open()){
        cerr << "Error al abrir el archivo" << "\n";
        return 1;
    }
    fp.read((char*)&n, sizeof(int));
    SaldoColaborador* arr = new SaldoColaborador[n];
    fp.read((char*)arr, sizeof(SaldoColaborador) * n);
    marica = puedeConsumir(arr[1].rut, SERV_DESAYUNO, "consumosD.txt");
    /*for (int i = 0; i < n; i++){
        cout << arr[i].rut << " " << arr[i].saldo_almuerzo << " " << arr[i].saldo_cena << " " << arr[i].saldo_desayuno << " " << arr[i].saldo_once << "\n";
        int eleccion;
        cout << "¿" << arr[i].rut << " que deseas consumir?:" << "\n";
        cout << "0 = Desayuno, 1 = Almuerzo, 2 = Once, 3 = Cena" << "\n";
        cin >> eleccion;
        puedeConsumir(arr[i].rut, eleccion, "consumosD.txt");
    }
    */
    fp.close();
    return 0;
}

// matigod