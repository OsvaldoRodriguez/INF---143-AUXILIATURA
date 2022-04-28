#include <bits/stdc++.h> // java.util.*;
using namespace std;
const int N = 1e5 + 100;
vector<int> G[N];
int vis[N];

void dfs(int u){
    cout << u << " \n";
    vis[u] = 1;
    for(int v : G[u])
        if(vis[v] == -1)
            dfs(v);
}


int main(){
    // n -> nodos
    // m -> cantidad de aristas
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        // para un grafo no dirigido
        // G[v].push_back(u);
    }

    for(int i = 0; i < n; i++){
        cout << i << " -> ";
        for(int v : G[i])
            cout << v << ' ';
        cout << endl;
    }
    // 3 maneras de 


    cout << "DFS\n";
    memset(vis, -1, sizeof vis);
    dfs(0);
    return 0;
}

