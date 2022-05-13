#include <bits/stdc++.h>
using namespace std;
const int  N = 1e3 + 10;

string teclado[3] = {"abcdefghij", "klmnopqrst", "uvwxyz{|}~"};
int vis[32][32];
int dis[34][35];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};


bool check(int a, int b){
    return a >= 0 and a < 3 and b >= 0 and b < 10;
}
void bfs(int a, int b, int fila){
    queue<pair<int, int>> q;
    vis[a][b] = 0;
    q.push({a, b});
    while(q.size() > 0){
        auto nodo_u = q.front();
        q.pop();
        int x = nodo_u.first;
        int y = nodo_u.second;
        for(int i = 0; i < 4; i++){
            int nw_x = x + dx[i];
            int nw_y = y + dy[i];
            if(check(nw_x, nw_y) and vis[nw_x][nw_y] == -1){
                vis[nw_x][nw_y] = vis[x][y] + 1;
                q.push({nw_x, nw_y});
            }
        }
    }

    // vamos a guardar esas distancias minimas en dis
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 10; j++){
            dis[fila][teclado[i][j] - 'a'] = vis[i][j];
        }
    }
}

int main (){


    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 10; j++){
            memset(vis, -1, sizeof vis);
            bfs(i, j, teclado[i][j] - 'a');

            

        }
    }
    
    int t;
    cin >> t;
    cin.ignore();
    string str;

    while(t--){
        int ans = 0;
        getline(cin, str);

        str = 'a' + str;
        for(int i = 1; i < str.size(); i++){


            if(str[i] == ' '){
                // cout << str[i - 1] << " espacio " << dis[str[i - 1] - 'a'][26] << '\n';
                ans += dis[str[i - 1] - 'a'][26];
            }else{
                // cout << str[i - 1] << " - " << str[i] << " " << dis[str[i - 1] - 'a'][str[i] - 'a'] << '\n';
                if(str[i - 1] == ' ')
                    ans += dis[26][str[i] - 'a'];
                else
                    ans += dis[str[i - 1] - 'a'][str[i] - 'a'];
            }
        }
        ans += dis[str[str.size() - 1] - 'a'][27];
        cout << ans << '\n';
    }

    return 0;
}
