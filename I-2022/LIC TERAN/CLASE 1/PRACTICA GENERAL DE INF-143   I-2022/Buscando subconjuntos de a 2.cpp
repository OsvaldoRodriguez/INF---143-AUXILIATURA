#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> A(n);
    for(ll &i : A)
        cin >> i;

    sort(A.begin(), A.end());
    ll s;
    while(q--){
        cin >> s;
        ll ans = 0;
        for(int i = 0; i < n; i++){

            if(A[i] >= s)
                continue;
            int a = i, b = n, mid;
            while(b - a > 1){
                mid = (a + b) / 2;
                if(A[mid] <= s - A[i])
                    a = mid;
                else
                    b = mid;
            }
            if(a != b){
                ans += (ll)(a - i);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
