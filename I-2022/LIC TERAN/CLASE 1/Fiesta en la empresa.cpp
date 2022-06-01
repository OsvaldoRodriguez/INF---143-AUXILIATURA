#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    // grafo
    vector<vector<int>> G(n + 1, vector<int>());
    vector<int> dis(n + 1, -1);

    // cola es del bfs
    queue<int> q;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        // grafo no dirigido;
        if(x != -1){
            G[x].push_back(i);
            G[i].push_back(x);
        }else{
            dis[i] = 1;
            q.push(i);
        }
    }


    // hacemos un bfs

    while(q.size() > 0){
        int u = q.front(); q.pop();
        for(int v : G[u]){
            if(dis[v] == -1){
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }

    cout << *max_element(dis.begin(), dis.end()) << "\n";
    return 0;
}
