//https://jv.umsa.bo/problem.php?cid=2426&pid=3

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 550;
const ll mod = 1e9 + 7;
set<ll> s;
vector<ll> ans;
void dfs(ll u){
    s.insert(u);
    ll dig = u % 10;
    for(ll i = max(0LL, dig - 1); i <= min(9LL, dig + 1); i++){
        if(u * 10LL + i <= 10000000000LL)
            dfs(u * 10LL + i);
    }
}

int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int casos;

    for(int i = 1; i <= 9; i++)
        dfs(i);

    for(ll i : s)
        ans.push_back(i);
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        cout << ans[x - 1] << '\n';

    }
    return 0;
 
}
