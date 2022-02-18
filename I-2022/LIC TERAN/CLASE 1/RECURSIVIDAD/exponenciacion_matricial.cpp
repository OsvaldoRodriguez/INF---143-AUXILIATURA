#include <bits/stdc++.h> // java.util.*
using namespace std;
const long long mod = 1e9 + 7;
typedef long long ll;
typedef vector<vector<ll>> matrix;

matrix mul_matrix(matrix A, matrix B){
    int n = (int) A.size();
    matrix ans(n, vector<ll> (n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                ans[i][j] = (ans[i][j] + A[i][k] * B[k][j]) % mod;
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

    matrix X = {{1, 2}, {3, 4}};

    matrix cur = potencia(X, 1000000000);
    mostrar(cur);
    

    return 0;
}




