// Ejercicio juez patito
#include <bits/stdc++.h>
using  namespace std;

long long dp[25][25]; // guardar las respuesta ya calculadas


/* complejidad de eso ses estados * transicion

    estados k  y n

    k, n  <= 20

    transiciones 

    n

    complejidad final O(k * n * n) -> O(k * n ^ 2)

    k = n

    O(n ^ 3)

*/

long long SuperSuma(int k, int n){
    if(k == 0)
        return dp[k][n] = n;
    if(dp[k][n] != -1)
        return dp[k][n];

    long long ans = 0;
    for(int i = 1; i <= n; i++){
        ans += SuperSuma(k - 1, i);
    }
    return dp[k][n] = ans;
}

// pasar de manera iterativa o usar programacion dinamica

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int k, n;
    while(cin >> k >> n){

        memset(dp, -1, sizeof dp);
        cout << SuperSuma(k, n) << '\n';
    }

}
