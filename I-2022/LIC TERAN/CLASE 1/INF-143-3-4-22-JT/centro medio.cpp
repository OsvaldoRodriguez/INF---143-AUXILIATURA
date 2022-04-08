// link https://jv.umsa.bo/problem.php?cid=2404&pid=0

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N = 1e3 + 10;
const ll mod = 1e9 + 7;
 
ll f(ll n){
    return n * (n + 1) / 2;
}
int main(){
     
    ll n;
    while(cin >> n){
 
        if(n == 1){
            cout << 1 << '\n';
            continue;
        }
        ll ans = -1;
        ll a = 1, b = n, mid;
        while(b - a > 1){
            mid = (a + b) / 2;
            ll L = f(mid - 1);
            ll R = f(n) - f(mid);
            if(L == R){
                ans = mid;
                break;
            }
            else if(L < R)
                a = mid;
            else
                b = mid;
        }
        if(ans != -1)
            cout << ans << "\n";
        else
            cout << "NO\n"; 
         
    }
    return 0;
}
