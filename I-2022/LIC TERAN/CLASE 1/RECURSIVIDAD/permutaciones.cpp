#include <bits/stdc++.h> // java.util.*
using namespace std;
typedef long long ll;
const int N = 20 + 5;

int elementos[N];
bool estado[N];
int n; // tamaño del conjunto

// algoritmo de fuerza bruta

// valor   -> saca una copia
// referencia   -> le pasa la direccion de memoria

void permutaciones(vector<int> &A){
    if(A.size() == n){
        // un permutacion valida

        // se aumenta el codigo
        for(int i = 0; i < n; i++)
            cout << A[i] << ' ';

        cout << '\n';
    }else{
        for(int i = 0; i < n; i++){
            if(estado[i] == false){ // no lo he tomado
                estado[i] = true;
                // push_back .- aniade un elemento al final de un vector
                A.push_back(elementos[i]);
                permutaciones(A);
                estado[i] = false;
                // eliminar el elemento de un vector
                A.pop_back();
            }
        }
    }
} 

int main(){


    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> elementos[i];

    vector<int> A;
    permutaciones(A);


    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    
    return 0;
}
 
 
