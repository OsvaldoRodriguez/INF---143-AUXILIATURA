#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int Parent[N]; 
int tamanio[N];

int nroConjuntos;
void build(int n){
    // cada nodo es representante de si mismo
    for(int i = 0; i <= n; i++){
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

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, acepta;
    // nodos y conexiones
    cin >> n >> m;
    nroConjuntos = n;
    build(n);

    while(m--){
        int a, b;
        cin >> a >> b >> acepta;
        if(acepta == 1)
            _join(a, b);

        cout << nroConjuntos << '\n';
    }




    return 0;
}
