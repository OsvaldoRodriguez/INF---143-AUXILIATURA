//https://jv.umsa.bo/problem.php?id=2287
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int mod = 10007;
typedef long long ll;

// cada vector  ya tiene todo calculado de 1 a n
int F[N], DF[N], P[N], SF[N], HP[N];
int criba[N];


int _pow(int a, int b, int mod){
    if(b == 0)
        return 1;
    return (_pow((a % mod * a % mod) % mod, b / 2, mod) % mod * (b & 1 ? a : 1) % mod) % mod;
}


int main(){

    // lectura rapida
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    F[0] = DF[0] = DF[1] = 1;
    DF[2] = 2;
    for(int i = 1; i < N; i++){
        F[i] = (F[i - 1] % mod * i % mod) % mod;
        if(i > 2){
            DF[i] = (DF[i - 2] % mod * i % mod) % mod;
        }
    }

    // superfactorial
    SF[0] = 1;
    for(int i = 1; i < N; i++){
        SF[i] = (SF[i - 1] % mod * F[i] % mod) % mod;
    }
    // criba
    // 1 es primo , 0 no es primo
    for(int i = 0; i < N; i++)
        criba[i] = 1;

    criba[0] = criba[1] = 0;

    for(int i = 2; i < N; i++){
        if(criba[i] == 1){
            for(int j = i + i; j < N; j += i)
                criba[j] = 0;
        }
    }

    // for(int i = 0; i < 10; i++)
    //     cout << i << " " << criba[i] << endl;
    
    for(int i = 0; i < N; i++){
        if(criba[i] == 1){
            criba[i] = i;
        }else{
            criba[i] = 1;
        }
    }

    for(int i = 1; i < N; i++){
        criba[i] = (criba[i - 1] % mod * criba[i] % mod) % mod;
    }

    //

    HP[0] = 1;
    for(int i = 1; i < N; i++)
        HP[i] = (HP[i - 1] % mod * _pow(i, i, mod) % mod) % mod; 
    

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << F[n] << " " << DF[n] << " " << criba[n] << " " << SF[n] << " " << HP[n] << '\n';
    }

    return 0;
}
