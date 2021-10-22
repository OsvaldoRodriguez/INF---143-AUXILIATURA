//https://jv.umsa.bo/problem.php?id=2298

#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e7 + 5;
typedef long long ll;
int v[N];
ll pr[N];
int cur = 0;
void criba(){
    v[0] = v[1] = 1;
    for(int i = 2; i * i < N; i++){
        if(!v[i]){
            for(int j = i * i; j < N; j += i){
                v[j] = 1;
            }
        }
    }
 
    for(int i = 0; i < N; i++)
        if(!v[i]){
            pr[cur++] = (ll)i;
        }
 
    for(int i = 1; i < cur; i++)
        pr[i] += pr[i - 1];    
}
 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    criba();
 
    int q;
    cin >> q;
    while(q--){
        ll x;
        cin >> x;
        int a = 0, b = cur, mid;
        while(b - a > 1){
            mid = (a + b) >> 1;
            if(pr[mid] <= x)
                a = mid;
            else
                b = mid;
        }
 
        cout << a << '\n';
    }
 
    return 0;
 
}
