#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 50;
const ll mod = 1e9 + 7;

vector<int> G[N];
int vis[N];
struct punto{
    int x, y;
    punto(int x, int y){
        this -> x = x;
        this -> y = y;
    }    
};


struct nodos{
    int dis, o, s, destino;
    nodos(int dis, int o, int s, int destino){
        this -> dis = dis;
        this -> o = o;
        this -> s = s;
        this -> destino = destino;
    }

    void mostrar(){
        cout << "(" << dis << ", " << o << ", " << s << ", " << destino << ")";

    }
};

int distancia(punto A, punto B){
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y); 
}


bool cmp(nodos A, nodos B){
    if(A.dis == B.dis){
        if(A.o == B.o){
            if(A.s == B.s){
                return A.destino < B.destino;
            }
            return A.s < B.s;
        }
        return A.o < B.o;
    }
    return A.dis < B.dis;
}

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

    int n;
    while(cin >> n){
        if(n == 0)
            break;

        vector<punto> v(n, punto(0, 0));
        for(int i = 0; i < n; i++){
            cin >> v[i].x >> v[i].y;
            //
            G[i].clear();
        }


        // construir el grafo

        for(int i = 0; i < n; i++){
            vector<nodos> aux;
            for(int j = 0; j < n; j++){
                if(i == j)
                    continue;

                aux.push_back((nodos){distancia(v[i], v[j]), abs(v[i].x - v[j].x), abs(v[i].y - v[j].y), j});
            }
            sort(aux.begin(), aux.end(), cmp);
            // cout << i << " -> ";
            // for(int j = 0; j < aux.size(); j++)
            //     aux[j].mostrar();
            // cout << endl;

            for(int j = 0; j < min(2, (int) aux.size()); j++){
                G[i].push_back(aux[j].destino);
            }            
        }


        // recorro el grafo
        for(int i = 0; i < n; i++)
            vis[i] = -1;

        dfs(0);

        bool visited = true;
        for(int i = 0; i < n; i++){
            if(vis[i] == -1)
                visited = false;
        }

        if(visited)
            cout << "Chapare protegido\n";
        else
            cout << "Chapare no Protegido\n";





    }

    return 0;
}
