#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const ll B = 331;
const int N = 1e5 + 5;
ll h1[N];
ll Base[N];
void Hash(string &s, ll base){
    ll h = 0;
    int n = (int) s.size();
    Base[0] = 1;
    for(int i = 0; i < n; i++){ 
        h = ((h % mod * base % mod) % mod + (ll)s[i] % mod) % mod;
        h1[i] = h;
        if(i > 0)
            Base[i] = (Base[i - 1] % mod * B % mod ) % mod;
    }

    // for(int i = 0; i < n; i++){
    //     cout << "subcadena " << s.substr(0, i + 1) << " ";
    //     cout << h1[i] << "\n";
    // }

    // for(int i = 0; i < n; i++){
    //     cout << Base[i] << "\n";
    // }
}

ll HHash(string &s, ll base){
    ll h = 0;
    int n = (int) s.size();
    for(int i = 0; i < n; i++){ 
        h = ((h % mod * base % mod) % mod + (ll)s[i] % mod) % mod;
    }
    return h;
}


ll getLR(int L, int R){
    if(L == 0)
        return h1[R];
    return (h1[R] % mod  - (h1[L - 1] % mod * Base[R - L + 1] % mod) % mod + mod) % mod ;
}

int main(){
    string s, t;
    cin >> s >> t;
    Hash(s, 331);
    int len_t = (int) t.size();
    ll hash_t = HHash(t, 331);
    cout << hash_t << endl;
    for(int i = 0; i < (int)s.size() - (int) t.size() + 1; i++){
        if(hash_t == getLR(i, i + len_t - 1)){
            cout << t << " aparece en la posicion " << i << endl;
        }
    }

    




    // cout << (Hash(s, 331) == Hash(t, 331) ? "IGUALES" : "NO SON IGUALES") << "\n";
    // cout << s << " vale : " << Hash(s, 331) << '\n';
    // cout << t << " vale : " << Hash(t, 331) << '\n';





}
