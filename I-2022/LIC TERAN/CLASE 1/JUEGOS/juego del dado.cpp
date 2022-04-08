#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N = 1e3 + 10;
const ll mod = 1e9 + 7;

void mago(){
    string respuesta;
    int a, b, c;
    cin >> a >> b >> c;
    cout << "piensa un numero entre [1, 6]\n";
    cout << a << " " << b << " " << c << " \n esta tu numero aqui?  N/S\n";
    cin >> respuesta;
    if(respuesta == "N"){
        cout << 7 - a << " " << 7 - b << " " << 7 - c << "\n esta tu numero aqui?\n";
        cin >> respuesta;
        if(respuesta == "S")
            cout << "MAGIA\n";

    }else
        cout << "MAGIA\n";
}

int main(){
    
    mago();

    return 0;
}
