#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 50;
const ll mod = 1e9 + 7;

vector<int> G[N];
int vis[N];
int cnt = 0;

// n -> nodos, m -> vertices
// O(n + m)
void dfs(int u){
    vis[u] = 1;
    cnt++;
    for(int v : G[u])
        if(vis[v] == -1)
            dfs(v);
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        // n -> # nodos
        // m -> # aristas
        int n, m;

        cin >> n;

        // limpiar el grafo
        for(int i = 0; i < n; i++){
            G[i].clear();
            vis[i] = -1;
        }


        for(int i = 0; i < n; i++){
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            G[u].push_back(v);
        }
        
        int ans = 0;
        int nodo = -1;
        for(int i = 0; i < n; i++){             // O(n)
            for(int j = 0; j < n; j++)
                vis[j] = -1;
            cnt = 0;
            dfs(i);                             // O(n + m)
            if(cnt > ans){
                ans = cnt;
                nodo = i;
            }

        }
        cout << nodo + 1 << '\n';
        // O(n * n + n * m)
        // O(n ^ 2)


    }
    return 0;
}
