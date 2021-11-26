// https://jv.umsa.bo/problem.php?cid=2351&pid=1
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 50;
typedef long long ll;
const ll mod = 1e9 + 7;
 
int n, k;
int A[N];
int dp[N];
 
/*
O (estados a memorizar * transicion)
O (N * k)
 
Complejidad
Tiempo:
    O(N * K)
 
Espacio:
    O(N)
*/
 
 
 
 
 
int f(int i){
 
    if(i == n - 1){
        return 0;
    }
 
    int &ans = dp[i];
 
    if(ans != -1)
        return ans;
 
    ans = 1e9;
 
    for(int j = 1; j <= k; j++){
        if(i + j <= n - 1){
            ans = min(ans, f(i + j) + abs(A[i] - A[i + j]));
        }
    }
 
    return ans;
}
 
 
void build(int i){
    if(i == n - 1){
        return;
    }
 
    int ans = dp[i];
 
    for(int j = 1; j <= k; j++){
        // ans = min(ans, f(i + j) + abs(A[i] - A[j]));
 
 
        if(i + j <= n - 1 and ans == f(i + j) + abs(A[i] - A[i + j])){
            cout << i + j + 1 << " ";
            build(i + j);
            break;
            return;
        }
    }
 
}
 
 
 
 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> A[i];
 
    memset(dp, -1, sizeof dp);
    int ans = f(0);
    cout << ans << '\n';
 
    return 0;
 
}
 
