#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
typedef long long ll;
ll ST[4 * N + 10];
int A[N];

ll f(ll a, ll b){
    return a + b;
}

// Complejidad O(n)
void build(int nodo, int l, int r){
    if(l == r){
        ST[nodo] = A[l];
        return;
    }
    int m = (l + r) / 2;
    // construir el hijo izquierdo
    build( nodo * 2, l, m);
    // construir el hijo derecho
    build(nodo * 2 + 1, m + 1, r);
    // contruir la respuesta

    // PADRE = HIJO IZQUIERDO + HIJO DERECHO
    ST[nodo] = f(ST[nodo * 2], ST[nodo * 2 + 1]);
}


// complejidad O(log n)
ll query(int nodo, int l, int r, int L, int R){
    // rango l, r me sirve a mi respuesta
    if(l >= L and r <= R){
        return ST[nodo];
    }
    int m = (l + r) / 2;
    // para el hijo izquierdo
    if(R <= m){
        return query(nodo * 2, l, m, L, R);
    }
    // necesitamos respuesta del hijo derecho
    if(L > m){
        return query(nodo * 2 + 1, m + 1, r, L, R);
    }
    return f(query(nodo * 2, l, m, L, R), query(nodo * 2 + 1, m + 1, r, L , R));
}



// Complejidad O(log n)
void update(int nodo, int l, int r, int pos, int val){
    if(l == r){
        ST[nodo] = val;
        return;
    }

    int m = (l + r) / 2;
    // hijo izquierdo
    if(pos <= m)
        update(nodo * 2, l, m, pos, val);
    else
        update(nodo * 2 + 1, m + 1, r, pos, val);

    // PADRE = HIJO IZQUIERDO + HIJO DERECHO
    ST[nodo] = f(ST[nodo * 2], ST[nodo * 2 + 1]);
}

int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){

        int n, q;
        cin >> n >> q;
        for(int i = 0; i < n; i++)
            cin >> A[i];
        // construccion del segment tree;
        build(1, 0, n - 1);
        char ope;
        int a, b;
        while(q--){
            cin >> ope >> a >> b;
            if(ope == 'P'){
                // a es L, b  es R
                cout << query(1, 0, n - 1, a - 1, b - 1) << '\n';
            }else{
                // a es la posicion 
                // b es el valor
                update(1, 0, n - 1, a - 1, b);
            }
        }
    }


    
    
    return 0;
}
