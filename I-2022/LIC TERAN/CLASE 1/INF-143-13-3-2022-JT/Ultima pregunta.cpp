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
    
    // O(n) = t * n
    // O(n) = 10^4 * 10^5 = 10^9   (no sirve)

    // O(n) = t * 1
    // O(n) = t
    
   

    ll n;
    cin >> n;


    ll cur_1 = n / 2;
    ll cur_2 = (n - 1) / 2;


    // if(expresion){
    //     // verdadero
    // }else{
    //     // false
    // }

    // ( expresion ?  true : false);

    ll num = (1LL + cur_1 * 3LL + cur_2 * 2LL) * 100LL + (n % 2 == 0 ? 42LL : 92LL);
    cout << num << '\n';

    // n es par
    //     k + 42; 
    // else
    //     k + 92 

}   


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}
 
 
