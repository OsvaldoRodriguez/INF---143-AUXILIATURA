#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50;
const ll mod = 1e9 + 7;

vector<int> G[N];
int vis[N];

bool flag = false;

void dfs(int u){
    for(int v : G[u]){
        if(vis[v] == -1){
            // ya visite el nodo v, pero estoy procesando sus hijos
            vis[v] = 0;
            dfs(v);
            // ya visite el nodo v, y ya procede todos sus hijos
            vis[v] = 1;   
        }else if(vis[v] == 0){
            flag = true;
        }
    }
}
int main(){


    int t;
    cin >> t;
    while(t--){
        // n -> # nodos
        // m -> # aristas
        int n, m;

        cin >> n >> m;

        // limpiar el grafo
        for(int i = 0; i < n; i++){
            G[i].clear();
            vis[i] = -1;
        }


        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            G[u].push_back(v);
        }
        // voy a asumir que no existe ciclo en el grafo
        flag = false;
        for(int i = 0; i < n; i++){
            if(vis[i] == -1){
                dfs(i);
            }
        }

        if(flag)
            cout << "Tiene Ciclo\n";
        else
            cout << "No Tiene\n";

    }
    return 0;
}
