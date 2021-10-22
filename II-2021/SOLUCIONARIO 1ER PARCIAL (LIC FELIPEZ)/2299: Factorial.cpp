//https://jv.umsa.bo/problem.php?id=2299
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2 * 1e5 + 5;
typedef long long ll;
const ll mod = 1e9 + 7;
ll f(ll x){
    ll ans = 1;
    for(ll i = 1; i <= x; i++)
        ans = (ans % mod * i % mod) % mod;
    return ans;
}
 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        short x;
        cin >> x;
        int a = -1, b = 1, c;
        for(int i = 1; i <= x; i++){
            c = a + b; 
            a = b;
            b = c;
        }
        cout << f((ll)c) << '\n';
    }
     
 
    return 0;
 
}
