#include <bits/stdc++.h> // java.util.*
using namespace std;
typedef long long ll;
const int N = 22;
int n; // tamaño del conjunto
int v[N]; // conjunto;

bool estado[N]; // mascara del conjunto (representa a un subconjunto)

void subconjuntos(int i){
    if(i == n){
        // ya tengo un subconjunto;
        cout << "{ ";
        for(int i = 0; i < n; i++){
            if(estado[i] == true){
                cout << v[i] << ' ';
            }
        }
        cout << "} \n";

    }else{
        estado[i] = false; // no tomar
        subconjuntos(i + 1);

        // tomar un elemento
        estado[i] = true;
        subconjuntos(i + 1);
    }
}


int main(){
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> v[i];

    subconjuntos(0);

    return 0;
}
 
 
