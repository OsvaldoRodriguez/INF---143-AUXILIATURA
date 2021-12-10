#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll pot(ll a, ll b, ll mod){
    ll ans = 1;
    for(int i = 1; i <= b; i++)
        ans = (ans % mod * a % mod) % mod;

    return ans;
}

// O(n ^ 3)
vector<vector<int>> mult_matrix(vector<vector<int>> &A, vector<vector<int>> &B, ll mod){
    int n = A.size();
    vector<vector<int>> ans(n, vector<int> (n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ll cur = 0;
            for(int k = 0; k < n; k++){
                cur = (cur + (A[i][k] % mod * B[k][j] % mod) % mod) % mod;

            }
            ans[i][j] = cur;
        }
    }


    return ans;

}


ll pot1(ll a, ll b, ll mod){
    ll ans = 1;

    while(b){
        if(b & 1)
            ans = (ans % mod * a % mod) % mod;
        b /= 2;
        a = (a % mod * a % mod) % mod;
    }
    return ans;
}


ll fast_sum(ll a, ll b, ll mod){
    ll ans = 0;

    while(b){
        if(b & 1)
            ans = (ans % mod + a % mod) % mod;
        b /= 2;
        a = (a % mod + a % mod) % mod;
    }
    return ans;
}



vector<vector<int>> fast_matrix(vector<vector<int>> &A, ll b, ll mod){
    int n = A.size();
    vector<vector<int>> ans(n, vector<int> (n, 0));

    for(int i = 0; i < n; i++){
        ans[i][i] = 1;
    }

    while(b){
        if(b & 1)
            ans = mult_matrix(ans, A, mod);
        b /= 2;
        A = mult_matrix(A, A, mod);
    }
    return ans;
}

void print(vector<vector<int>> &A){
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A[i].size(); j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){

    ll a = 10,  b = 51, mod = 1e9 + 7;
    // cin >> a >> b;
    int n;
    cin >> n >> b;

    vector<vector<int>> A(n, vector<int> (n));
    vector<vector<int>> ANS(n, vector<int> (n));

    for(int i = 0; i < n; i++){
        ANS[i][i] = 1;
        for(int j = 0; j < n; j++)
            cin >> A[i][j];
    }


    // print(ANS);
    

    auto tmp = fast_matrix(A, b, mod);   // O(log (b) * n ^ 3)
    print(tmp);

    

    return 0;
}
