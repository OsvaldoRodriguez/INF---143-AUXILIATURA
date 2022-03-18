#include <bits/stdc++.h> // java.util.*
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
const ll mod = 1e9 + 7;
const long double E = 1e-9;


// O(n) 
bool is_prime(ll n){
    int cnt = 0;                        // 1
    for(ll i = 1; i <= n; i++){        // n + 1 operaciones
        if(n % i == 0){                 // n
            cnt++;                      // n
        }
    }    

    if(cnt == 2)                        // 1
        return true;                    // 1
    return false;

}

bool is_prime2(ll n){
    for(ll i = 2; i * i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }

    return true;
}

void solve(){ 
    

    
    // T(n) = 3 * n + 4
    /*
        T(n) = 3 * n + 4
        O(T(n)) = 3 * n
        O(T(n)) = n  (Complejidad Lineal)


    */

    ll n = INT_MAX;
    cout << n << '\n';
    cout << is_prime(n) << '\n';

    // T(n) = 2 * n ^ 2 + n + 1
    // O(T(n)) = 2 * n ^ 2
    // O(T(n)) = n ^ 2

}   


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}
 
 
