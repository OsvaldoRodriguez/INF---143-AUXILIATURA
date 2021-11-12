#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;
typedef long long ll;
ll dp[N];


// estados por transcicion
// O(n)
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


int main(){

    ll n;
    cin >> n;

    memset(dp, -1, sizeof dp);
    cout << "con PROGRAMACIÓN DINAMICA\n";
    cout << ff(n) << '\n';

    cout << "sin PROGRAMACIÓN DINAMICA\n";
    cout << f(n) << '\n';
    return 0;
}
