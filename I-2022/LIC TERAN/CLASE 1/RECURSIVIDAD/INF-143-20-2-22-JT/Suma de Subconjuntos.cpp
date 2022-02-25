#include <bits/stdc++.h> // java.util.*
using namespace std;
typedef long long ll;
const int N = 22;
int n, suma; // tamaño del conjunto
int v[N]; // conjunto;
int nro_subconjuntos_validos;
bool estado[N]; // mascara del conjunto (representa a un subconjunto)

void subconjuntos(int i){
    if(i == n){
        // ya tengo un subconjunto;
        // cout << "{ ";

        // aqui va su codigo del problema
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(estado[i] == true){
                // cout << v[i] << ' ';
                sum += v[i];
            }
        }

        if(sum == suma){
            nro_subconjuntos_validos += 1;
        }
        // cout << "} \n";

    }else{
        estado[i] = false; // no tomar
        subconjuntos(i + 1);

        // tomar un elemento
        estado[i] = true;
        subconjuntos(i + 1);
    }
}


int main(){


    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    while(cin >> suma >> n){
        for(int i = 0; i < n; i++)
            cin >> v[i];

        nro_subconjuntos_validos = 0;
        subconjuntos(0);
        cout << nro_subconjuntos_validos << '\n';
    }
    return 0;
}
 
 
