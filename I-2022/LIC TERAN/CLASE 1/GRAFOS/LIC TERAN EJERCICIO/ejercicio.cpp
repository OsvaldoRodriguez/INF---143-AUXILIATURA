#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 50;
const ll mod = 1e9 + 7;
int n, m; 
char A[N][N];
int dis[N][N];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct par{
    int x, y;
    par(int x, int y){
        this -> x = x;
        this -> y = y;
    }
};

bool ok(int a, int b){
    return a >= 0 and a < n and b >= 0 and b < m and A[a][b] != '#';
}

bool dfs(int x, int y, int ini, int init){
    A[x][y] = '@';
    if(x == ini and y == init)
        return true;
    for(int i = 0; i < 4; i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if(ok(new_x, new_y)){
            if(dis[x][y] - 1 == dis[new_x][new_y]){
                if(dfs(new_x, new_y, ini, init))
                    return true;
            }
        }
    }
    return false;
}

void bfs(int x, int y){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dis[i][j] = 1e9;

    queue<par> q;
    q.push((par) {x, y});
    dis[x][y] = 0;

    while(q.size() > 0){
        par cur = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int new_x = cur.x + dx[i];
            int new_y = cur.y + dy[i];
            if(ok(new_x, new_y)){
                if(dis[cur.x][cur.y] + 1 < dis[new_x][new_y]){
                    dis[new_x][new_y] = dis[cur.x][cur.y] + 1;
                    q.push((par){new_x, new_y});
                }
            }
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         printf("%4d", dis[i][j]);
    //     }
    //     printf("\n");
    // }
    int yi = -1, mn = 1e9;

    for(int i = 0; i < m; i++){
        // cout << dis[n - 1][i] << endl;
        if(dis[n - 1][i] < mn){
            mn = dis[n - 1][i];
            yi = i; 
        }
    }

    // cout << n - 1 << " " << yi << " " << mn << endl; 
    // reconstruir camino

    dfs(n - 1, yi, x, y);



    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i][j] != '@')
                A[i][j] = '.';
            cout << A[i][j];
        }
        cout << endl;
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> A[i][j];

    // iniciar
    int x, y;

    cin >> x >> y;

    bfs(x, y);




    return 0;
}
