#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f(ll n){
    if(n <= 1)
        return n;
    return 4 * f(n - 1) - 4 * f(n - 2);
}

ll g(ll n){
    // 1 << n = 2 ^ n
    return ( n * (1LL << n) ) / 2;
}

int main(){
    ll n;
    cin >> n;
    cout << f(n) << " " << g(n) << endl;
    return 0;
}


// fuerza bruta
// subsets, permutations, backtraking
// busqueda y ordenamiento (busqueda binaria, ordenamiento (merg sort))
// modulacion, exponenciacion binaria
