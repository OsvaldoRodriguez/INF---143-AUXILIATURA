#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;

int ST[4 * N + 10];
int A[N];

int f(int a, int b){
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
int query(int nodo, int l, int r, int L, int R){
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

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];

    build(1, 0, n - 1);
    cout << "SEGMENT TREE\n";
    for(int i = 0; i < 20; i++)
        cout << i << " " << ST[i] << endl;

    int L, R;
    cin >> L >> R;
    cout << query(1, 0, n - 1, L, R) << '\n';

    update(1, 0, n - 1, 3, 1);

    cout << "SEGMENT TREE DESPUES DEL UPDATE\n";
    for(int i = 0; i < 20; i++)
        cout << i << " " << ST[i] << endl;

    return 0;
}
