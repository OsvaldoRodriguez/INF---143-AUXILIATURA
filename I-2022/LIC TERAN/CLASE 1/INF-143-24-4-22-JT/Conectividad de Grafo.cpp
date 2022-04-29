//https://jv.umsa.bo/problem.php?cid=2428&pid=0
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 550;
const ll mod = 1e9 + 7;
vector<int> G[30];
int vis[30];

void dfs(int u){
    vis[u] = 1;
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
    cin.ignore();
    cin.ignore();
    string len, arcos;
    bool flag = true;
    while(t--){
        getline(cin, len);
        int n = len[0] - 'A';
        // cout << len << ' ' << n  << endl;
        for(int i = 0; i <= n; i++){
            G[i].clear();
            vis[i] = -1;
        }
        while(getline(cin, arcos)){
            if(arcos == "")
                break;
            // cout << arcos << '\n';
            G[arcos[0] - 'A'].push_back(arcos[1] - 'A');
            G[arcos[1] - 'A'].push_back(arcos[0] - 'A');
        }
        // aqui termina un caso;

        int componentes = 0;

        for(int i = 0; i <= n; i++){
            if(vis[i] == -1){
                componentes++;
                dfs(i);
            }
        }
        if(!flag){
            cout << "\n";
        }
        flag = false;
        cout << componentes << '\n';

    }

    return 0;
 
}
