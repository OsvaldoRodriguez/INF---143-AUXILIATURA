#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
typedef long long ll;
ll ST[4 * N + 10], LAZY[4 * N + 10];
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

// (Complejidad O(1))
void propagate(int nodo, int l, int r){
    if(LAZY[nodo] != 0){
        ST[nodo] += (r - l + 1) * LAZY[nodo];
        if(l != r){
            LAZY[nodo * 2] += LAZY[nodo];
            LAZY[nodo * 2 + 1] += LAZY[nodo];
        }
        LAZY[nodo] = 0;
    }
}

// Complejidad O(log n)
ll Query(int nodo, int l, int r, int L, int R){
    // rango l, r me sirve a mi respuesta
    propagate(nodo, l, r);
    if(l >= L and r <= R){
        return ST[nodo];
    }
    int m = (l + r) / 2;
    // para el hijo izquierdo
    if(R <= m){
        return Query(nodo * 2, l, m, L, R);
    }
    // necesitamos respuesta del hijo derecho
    if(L > m){
        return Query(nodo * 2 + 1, m + 1, r, L, R);
    }
    return f(Query(nodo * 2, l, m, L, R), Query(nodo * 2 + 1, m + 1, r, L , R));
}


// Complejidad O(log n)
void Update(int nodo, int l, int r, int L, int R, int val){
    propagate(nodo, l, r);
    if(r < l or L > r or R < l)
        return; 
    if(l >= L and r <= R){
        LAZY[nodo] += val;
        propagate(nodo, l, r);
    }else{
        int m = (l + r) / 2;
        Update(nodo * 2, l, m, L, R, val);
        // necesitamos respuesta del hijo derecho
        Update(nodo * 2 + 1, m + 1, r, L, R, val);
        ST[nodo] = f(ST[nodo * 2], ST[nodo * 2 + 1]);
    }

}



void mostrar(){
    cout << "SEGMENT TREE\n";
    for(int i = 0; i < 20; i++)
        cout << "(" << i << ", " << ST[i] << ")";
    cout << endl;
    cout << "SEGMENT TREE LAZY\n";
    for(int i = 0; i < 20; i++)

        cout << "(" << i << "," << LAZY[i] << ")";
    cout << endl;

}

int main(){


    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
        
    int n, q;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];
    build(1, 0, n - 1);

    
    cout << Query(1, 0, n - 1, 1, 6) << '\n';
    mostrar();
    Update(1, 0, n - 1, 2, 3, 2);
    mostrar();

    cout << Query(1, 0, n - 1, 2, 5) << '\n';
    mostrar();
    cout << Query(1, 0, n - 1, 0, 2) << '\n';
    mostrar();

    cout << Query(1, 0, n - 1, 3, 3) << '\n';
    mostrar();
    

    return 0;
}
