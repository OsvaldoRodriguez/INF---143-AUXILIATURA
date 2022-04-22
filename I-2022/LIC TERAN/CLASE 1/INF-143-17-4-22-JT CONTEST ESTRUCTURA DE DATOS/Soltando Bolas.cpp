#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
const ll mod = 1e9 + 7;

bool vis[N];
int final;
int n, p;
void proceso(int prof, int nodo){
    if(prof == n){
        final = nodo;
        return;
    }

    int izquierda = nodo * 2;
    int derecha = nodo * 2 + 1;
    if(vis[nodo] == false){
        vis[nodo] = true;
        proceso(prof + 1, izquierda);
    }else{
        vis[nodo] = false;
        proceso(prof + 1, derecha);
    }
}

int main(){
        
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> p;
        // (1 << n) = 2 ^ n
        for(int i = 1; i <= (1 << n) + 5; i++)
            vis[i] = false;
        for(int i = 1; i <= p; i++)
            proceso(1, 1);
        cout << final << '\n';
    }
    return 0;
}
