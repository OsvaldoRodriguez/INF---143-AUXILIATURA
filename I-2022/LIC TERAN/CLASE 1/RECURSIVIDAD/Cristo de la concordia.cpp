#include <bits/stdc++.h> // java.util.*
using namespace std;
const long long mod = 1e9 + 7;
typedef long long ll;
typedef vector<vector<ll>> matrix;
// cuantos formas hay para llegar a la grada n, haciendo saltos de tipo 1,2,3 
ll go(ll n, int tipo_salto){
    if(n < 0)
        return 0;
    if(n == 0)
        return 1;

    int ans = 0;
    if(tipo_salto <= 2){
        ans = (ans + go(n - 1, 1) + go(n - 2, 2) + go(n - 3, 3));
    }else{
        ans = (ans + go(n - 1, 1) + go(n - 2, 2));    
    }
    return ans;
}
/*
go -> complejidad es O(2^n)

al usar Programacion dinamica -> O(n)  (sigue lento)

                                3 + 1     3 + 2
f(n) = 1 * f(x - 1) + 1 * f(x - 2) + 1 * f(x - 4) +  1 * f(x - 5)


f(n)
1 1 0 1 1
1 0 0 0 0
0 1 0 0 0
0 0 1 0 0
0 0 0 1 0




f(n) = f(n - 1) + f(n - 2)


X^n * || = respuesta






*/   



matrix mul_matrix(matrix A, matrix B){
    int n = (int) A.size();
    matrix ans(n, vector<ll> (n, 0LL));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                ans[i][j] = (ans[i][j] % mod + (A[i][k] % mod * B[k][j] % mod) % mod) % mod;
            }
        }
    }
    return ans;

}

void mostrar(matrix A){
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A[i].size(); j++)
            cout << A[i][j] << ' ';
        cout << '\n';
    }

}

matrix potencia(matrix X, ll e){ // log e
    if(e == 0){
        matrix ans(X.size(), vector<ll> (X.size(), 0));
        for(int i = 0; i < X.size(); i++)
            ans[i][i] = 1;
        return ans;
    }
    matrix tmp = potencia(mul_matrix(X, X), e / 2);
    if(e % 2 == 1)
        tmp = mul_matrix(tmp, X);
    return tmp;
}

matrix potencia1(matrix X, ll e){
    matrix ans(X.size(), vector<ll> (X.size(), 0));
    for(int i = 0; i < X.size(); i++)
        ans[i][i] = 1;
    while(e > 0){
        if(e % 2 == 1)
            ans = mul_matrix(ans, X);
        e /= 2;
        X = mul_matrix(X, X);
    }
    return ans;
}
int main(){

    matrix X = {    {1, 1, 0, 1, 1},
                    {1, 0, 0, 0, 0},
                    {0, 1, 0, 0, 0},
                    {0, 0, 1, 0, 0},
                    {0, 0, 0, 1, 0}};

    int n;
    cin >> n;
    while(n--){
        ll e;
        cin >> e;
        matrix cur = potencia(X, e);
        ll ans = (cur[0][0] + cur[3][0]) % mod;
        cout << ans << '\n';
    }
    // mostrar(cur);

    return 0;
}




