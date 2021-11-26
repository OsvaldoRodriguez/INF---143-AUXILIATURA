//https://jv.umsa.bo/problem.php?cid=2351&pid=7
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 50;
typedef long long ll;
const ll mod = 1e9 + 7;



bool ok(char x){
    return (x >= '2' and x <= '9') or x == 'A' or x == 'J' or x == 'K' or x == 'Q';
}

bool check(string &A){
    for(int i = 0; i < (int) A.size(); i++)
        if(!ok(A[i]))
            return false;
    return true;
}
int n, m;

string A, B;

int dp[1010][1010];

int f(int i, int j){

    if(i == n or j == m)
        return 0;

    int &ans = dp[i][j];
    
    if(ans != -1)
        return ans;

    ans = 0;
    if(A[i] == B[j]){
        ans = max(ans, f(i + 1, j + 1) + 1);
    }

    // descartar A[i]
    ans = max(ans, f(i + 1, j));
    // descartar B[j]

    ans = max(ans, f(i, j + 1));

    return ans;
}

void build(int i, int j){

    if(i == n or j == m)
        return;

    int ans = dp[i][j];
    
    if(A[i] == B[j] and ans == f(i + 1, j + 1) + 1){
        cout << A[i];
        build(i + 1, j + 1);
        return;
    }

    // descartar A[i]
    if(ans == f(i + 1, j)){
        build(i + 1, j);
        return;
    }
    // descartar B[j]
    if(ans == f(i, j + 1)){
        build(i, j + 1);
        return;
    }

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    while(cin >> A >> B){
        n = (int) A.size();
        m = (int) B.size();
        if(n != m)
            cout << "Deben tener la misma CANTIDAD DE CARTAS!!\n";
        else if(check(A) and check(B)){
            // resolver

            for(int i = 0; i <= n; i++)
                for(int j = 0; j <= m; j++)
                    dp[i][j] = -1;
            int ans = f(0, 0);
            cout << "La longitud de la Subsecuencia es: ";
            cout << ans << '\n';
            build(0, 0);
            cout << "\n";
            // LCS longest Common subsequence - Subsecuencia comun mas larga
        }else
            cout << "LAS CARTAS NO PERTENECEN A LA BARAJA!!\n";
    }
    return 0;

}


