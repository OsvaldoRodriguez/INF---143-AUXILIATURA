//https://jv.umsa.bo/problem.php?cid=2351&pid=3
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 50;
typedef long long ll;
const ll mod = 1e9 + 7;

int n;
int A[N][4];
int _map(char x){
    if(x == 'B')
        return 1;
    if(x == 'F')
        return 2;
    return 3;
}

int dp[N][2][2][2];

// O (estados a memorizar * transicion)
// O(i * B * F * W * 1)
// O(N * 2 * 2 * 2 * 1)
// O(8 * N)
// O(N)
int f(int i, bool B, bool F, bool W){
    if(i == n){
        if(B and F and W)
            return 0;
        return 1e9;
    }

    int &ans = dp[i][B][F][W];

    // si ya lo calcule, retorno lo calculado
    if(ans != -1)
        return ans;
    // comprar la pelotita

    ans = 1e9;
    ans = min(ans, f(i + 1, B or A[i][1], F or A[i][2], W or A[i][3]) + A[i][0]);
    // no comprar
    ans = min(ans, f(i + 1, B, F, W));
    return ans;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++){
        int costo;
        string str;
        cin >> costo >> str;
        A[i][0] = costo;
        for(int j = 0; j < (int) str.size(); j++){
            int pos = _map(str[j]);
            A[i][pos] = 1;
        }
    }

    memset(dp, -1, sizeof dp);
    int ans = f(0, 0, 0, 0);
    if(ans == 1e9)
        ans = -1;
    cout << ans << '\n';
    return 0;

}


