#include <bits/stdc++.h> // java.util.*;
using namespace std;
const int N = 1e5 + 100;
vector<int> G[N];
int vis[N];

void bfs(int nodo){

    memset(vis, -1, sizeof vis);
    queue<int> q;
    q.push(nodo);
    vis[nodo] = 0;
    // el bfs puede calcular el camino minimo
    while(q.size() > 0){
        int u = q.front();
        q.pop();
        cout << u << "\n";
        for(int v : G[u]){
            if(vis[v] == -1){
                vis[v] = vis[u] + 1;
                q.push(v);
            }
        }
    }
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


    cout << " BFS\n";
    bfs(0);
    for(int i = 0; i < n; i++)
        cout << "[ 0 -> " << i <<  "] dis minima es: " << vis[i] << endl;
    return 0;
}

