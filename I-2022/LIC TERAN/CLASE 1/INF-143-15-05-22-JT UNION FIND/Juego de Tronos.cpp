#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;

int Parent[N]; 
int tamanio[N];
int X[N], Y[N];
int nroConjuntos;
void build(int n){
    // cada nodo es representante de si mismo
    for(int i = 0; i < N; i++){
        Parent[i] = i;
        tamanio[i] = 1;
    }
}



// Compplejidad log n
int _find(int u){
    if(u == Parent[u])
        return u;
    return Parent[u] = _find(Parent[u]);
}


// Complejidad O(log n)
void _join(int u, int v){
    int pu = _find(u);
    int pv = _find(v);
    // si los representantes son diferentes se puede unir
    if(pu != pv){

        nroConjuntos--;
        // cout << "une " << u << " con " << v << ' ' << nroConjuntos << endl;
        if(tamanio[pu] < tamanio[pv]){
            Parent[pu] = pv;   
        }else{
            Parent[pv] = pu;
            if(tamanio[pu] == tamanio[pv]){
                tamanio[pu]++;
            }
        }
    }else{
        // cout << "ya son del mismo conjunto " << nroConjuntos << endl;  
    }


}

void procesar(int x, int y, int indice){
    if(X[x] != -1){
        _join(indice, X[x]);
    }

    if(Y[y] != -1)
        _join(indice, Y[y]);

    X[x] = indice;
    Y[y] = indice;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    memset(X, -1, sizeof X);
    memset(Y, -1, sizeof Y);
    build(n);
    nroConjuntos = n;
    for(int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        procesar(a, b, i);
    }

    int m;
    cin >> m;

    int suma = nroConjuntos;
    for(int i = 1; i <= m; i++){
        nroConjuntos++;
        int a, b;
        cin >> a >> b;
        procesar(a, b, i + n);
        suma += nroConjuntos;
    }

    cout << fixed << setprecision(2) << double(suma) / double(m + 1) << '\n';

    return 0;
}
