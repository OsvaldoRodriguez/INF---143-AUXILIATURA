//https://jv.umsa.bo/problem.php?cid=2351&pid=8
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 20 + 10;
 
int n;
int digitos[10];
 
int dp[20][11][4];
int dp2[20][11][4];
int f(int i, int dig, int suma){
 
    int &ans = dp[i][dig][suma];
    if(dig == 10)
        return ans = i == n and suma == 0;
 
    if(ans != -1){
        return ans;
    }
 
    ans = 0;
    for(int j = 0; j <= digitos[dig]; j++){
        if(i + j <= n){
            ans |= f(i + j, dig + 1, (suma + j * dig) % 3);
        }
    }
    return ans;
}
 
int formas(int i, int dig, int suma){
 
    int &r = dp2[i][dig][suma];
    if(dig == 10)
        return r = 1;
 
    if(r != -1){
        return r;
    }
 
    r = 0;
    int ans = dp[i][dig][suma];// si existe o no
    for(int j = 0; j <= digitos[dig]; j++){
        if(i + j <= n and ans == dp[i + j][dig + 1][(suma + j * dig) % 3]){
            r += formas(i + j, dig + 1, (suma + j * dig) % 3);
        }
    }
    return r;
}
 
void build(int i, int dig, int suma, int k){
 
    if(dig == 10)
        return;
 
     
    for(int j = 0; j <= digitos[dig]; j++){
        if(i + j <= n and k <= dp2[i + j][dig + 1][(suma + j * dig) % 3]){
            for(int k = 0; k < j; k++)
                cout << dig;
            build(i + j, dig + 1, (suma + j * dig) % 3, k);
            break;
            return;
        }
 
        if(dp2[i + j][dig + 1][(suma + j * dig) % 3] >= 0)
            k -= dp2[i + j][dig + 1][(suma + j * dig) % 3];
    }
}
 
 
 
 
 
 
 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n;
    for(int i = 0; i < 10; i++)
        cin >> digitos[i];
 
 
    memset(dp2, -1, sizeof dp2);
    memset(dp, -1, sizeof dp);
    int ans = f(0, 0, 0);
    if(ans == 0){
        cout << "NO\n";
    }else{
        int f = formas(0, 0, 0);
        build(0, 0, 0, f);
 
 
    }
     
 
    return 0;
 
}
 
