// https://jv.umsa.bo/problem.php?id=1167
#include <bits/stdc++.h> // java.util.*;
using namespace std;
const int N = 1e2 + 10; // 1e2 = 10^2
int G[N][N];
int dis[N][N];
int n, m;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
bool check(int a, int b){
    return a >= 0 and a < n and b >= 0 and b < m;
}

void bfs(int a, int b){
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dis[i][j] = 1e9;
    q.push({a, b});
    dis[a][b] = 0;

    while(q.size() > 0){
        pair<int, int> u = q.front(); 
        q.pop();
        int x = u.first;
        int y = u.second;
        int new_x, new_y;
        // aristas que tiene
        for(int i = 0; i < 4; i++){
            new_x = x + dx[i];
            new_y = y + dy[i];
            if(check(new_x, new_y)){
                if( dis[x][y] + G[new_x][new_y] <  dis[new_x][new_y]){
                    dis[new_x][new_y] = dis[x][y] + G[new_x][new_y];
                    q.push({new_x, new_y});
                }
            }
        }
    }


    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++)
    //         printf("%3d", dis[i][j]);
    //     printf("\n");
    // }

}

int main(){
    

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    int contador = 1;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                char x;
                cin >> x;
                if(x == '#')
                    G[i][j] = 1;
                else
                    G[i][j] = 0;
            }

        int xi, yi, xf, yf;
        cin >> xi >> yi >> xf >> yf;
        bfs(xi, yi);

        cout << "Laberinto #"<< contador++ << ": " << dis[xf][yf] << '\n';
    }

    return 0;
}

