#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;
typedef long long ll;
ll dp[3];


// estados por transcicion
// O(n)

// top down
ll ff(ll n){ // O(n)
    if(n <= 1)
        return n;

    if(dp[n] != -1) // si ya se calculo, retornar el valor
        return dp[n];
    return dp[n] = ff(n - 1) + ff(n - 2); // calcular y guardar
    // return ans;
}


ll f(ll n){  // O(2^n)
    if(n <= 1)
        return n;
    return f(n - 1) + f(n - 2);
}


// 0, 1, 1, 2, 3, 5, 8
   // 0  1  2  3  4 
void fibonacci(int n){
    // button up

    dp[0] = 0;
    dp[1] = 1;
    // eliminacion de una dimension
    for(int i = 2; i <= n; i++){
        dp[i % 2] = dp[(i - 1) % 2] + dp[(i - 2) % 2];
    }



    ll a = -1, b = 1, c;
    for(int i = 0; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }

    cout << c << " fibo 111";

}


int main(){

    ll n;
    cin >> n;

    cout << "button up\n";

    fibonacci(n);

    cout << dp[n % 2] << '\n';

    // memset(dp, -1, sizeof dp);
    // cout << "con PROGRAMACIÓN DINAMICA\n";
    // cout << ff(n) << '\n';

    cout << "sin PROGRAMACIÓN DINAMICA\n";
    cout << f(n) << '\n';
    return 0;
}
