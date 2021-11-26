//https://jv.umsa.bo/problem.php?cid=2351&pid=9
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 100 + 10;
 
string A[N];
string S;
int n;
int dp[N];
 
int f(int i){
    if(i == (int) S.size())
        return 0;
 
    int &ans = dp[i];
    if(ans != -1)
        return ans;
     
    ans = 1e9;
    for(int j = 0; j < n; j++){
        string subcad = A[j];
        if(i + (int)subcad.size() <= S.size()){
            int cost = 0;
 
            for(int k = 0; k < (int) subcad.size(); k++){
                cost += (subcad[k] != S[k + i]);
            }
 
            ans = min(ans, f(i + (int)subcad.size()) + cost);
        }
    }
    return ans;
 
}
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> S >> n;
 
    for(int i = 0; i < n; i++)
        cin >> A[i];
 
    //iniciar la tablita
 
    memset(dp, -1, sizeof dp);
    int resultado = f(0);
    if(resultado == 1e9)
        resultado = -1;
    cout << resultado << '\n';
 
    return 0;
 
}
