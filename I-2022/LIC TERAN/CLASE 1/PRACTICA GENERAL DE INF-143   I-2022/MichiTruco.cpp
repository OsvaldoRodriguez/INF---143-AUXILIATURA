#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200;
int P[N];


int FIND(int u){
    if(u == P[u])
        return u;
    return P[u] = FIND(P[u]);
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        P[i] = i;

    int nro_conjunto = n;
    int idioma;
    vector<set<int>> G(n + 1, set<int>());
    for(int i = 1; i <= n; i++){
        int len;
        cin >> len;
        for(int j = 0; j < len; j++){
            int idioma;
            cin >> idioma;
            G[i].insert(idioma);
        }
    }

    int aumento = 1;
    for(int i = 1; i <= n; i++){
        if(G[i].size() > 0)
            aumento = 0;
    }

    for(int i = 1; i <= n; i++){                        
        for(int j = i + 1; j <= n; j++){                
            for(int k : G[i]){                          
                if(G[j].count(k)){                      
                    int pu = FIND(i);
                    int pv = FIND(j);
                    if(pv != pu){
                        P[pv] = pu;
                        nro_conjunto--;
                    }
                }
            }
        }
    }

    cout << nro_conjunto - 1 + aumento << " michidolares\n";


    return 0;
}
