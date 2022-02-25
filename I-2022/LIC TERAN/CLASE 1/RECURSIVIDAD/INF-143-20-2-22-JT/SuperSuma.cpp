https://jv.umsa.bo/contest.php?cid=2384
#include <bits/stdc++.h> // java.util.*
using namespace std;
typedef long long ll;
const int N = 20 + 5;

ll dp[N][N];

ll super_suma(int k, int n){
    if(k == 0)
        return n;

    // si ya lo calcule, pues recuerdo
    if(dp[k][n] != -1){
        return dp[k][n];
    }
    // si no lo he calculado
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += super_suma(k - 1, i);
    }
    dp[k][n] = ans;
    return dp[k][n];
}

int main(){


    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k, n;
    while(cin >> k >> n){
        for(int i = 0; i <= k; i++)
            for(int j = 0; j <= n; j++)
                dp[i][j] = -1;
        cout << super_suma(k, n) << '\n';
    }
    
    return 0;
}
 
 
