#include <bits/stdc++.h> // java.util.*
using namespace std;
typedef long long ll;
const int N = 20 + 5;

int n; // tamaño del conjunto


int main(){


    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> elementos[i];
    // vector ordenado (menor a mayor)
    // debe teener elementos unicos el vector (no repetidos)
    do{

        for(int i = 0; i < n; i++){
            cout << elementos[i] << ' ';
        }
        cout << endl;
    }while(next_permutation(elementos, elementos + n));
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    
    return 0;
}
 
 
