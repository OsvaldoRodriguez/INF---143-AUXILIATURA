#include <bits/stdc++.h>
using namespace std;
 
vector <int> G[200];
int vis[200];
map<string, int> m;
map<int, string> palabra;
 
 
bool dfs(int u){
    cout << palabra[u] << "\n";
    if(vis[u] == 1)
        return true;
    vis[u] = 1;

    bool ans = false;
    for(int v : G[u]){
        if(vis[v] == -1){
            if(dfs(v))
                return ans = true;
        }
    }
    return ans;
     
}
int main() {
     
    string str;
    // Hola -> 1
    // que -> 2
    // tal -> 3
    int nodo = 1;
    int last = -1;
         
    getline(cin, str);
         
        for(int i = 0; i < str.size(); i++)
            str[i] = toupper(str[i]);
             
        // cout << str << endl;
         
        for(int i = 0; i < str.size(); i++){
            string aux = "";
            while(i < str.size() and (str[i] >= 'A' and str[i] <= 'Z')){
                aux += str[i++];
            }
             
            int u, v;
            if(m.count(aux) == 0){
                m[aux] = nodo;
                palabra[nodo] = aux;
                v = nodo;
            }else{
                v = m[aux];
            }

            u = last;
            // cout << last << " " << nodo << endl;
            //     cout << palabra[last] << " " << palabra[nodo] << endl;
                 
            if(last == -1){
                last = nodo;
            }else{
                // cout << u << "  " << v <<endl;
                G[u].push_back(v);
                last = nodo;
            }
            nodo++;
        }
         
         
         
     
     
    string cadena;
    cin >> cadena;
    memset(vis, -1, sizeof vis);
    dfs(m[cadena]);
     
    return 0;
}
