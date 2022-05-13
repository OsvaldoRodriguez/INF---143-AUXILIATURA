#include <bits/stdc++.h>
using namespace std;
const int  N = 1e3 + 10;
int A[N][N];
int D[N][N];
int n, m;

int costos[][5] = {{7, 6, 5, 6, 7},
                    {6, 3, 2, 3, 6},
                    {5, 2, 0, 2, 5},
                    {6, 3, 2, 3, 6},
                    {7, 6, 5, 6, 7}};

bool check(int a, int b){
    return a >= 1 and a <= n and b >= 1 and b <= m and A[a][b] == 1;
}

void bfs_0_K(int x1, int y1, int x2, int y2){

    queue<pair<int, int>> colas[8];
    int total_nodos = 1;
    colas[0].push({x1, y1});
    D[x1][y1] = 0;

    int idx = 0;

    while(total_nodos > 0){
        while(colas[idx].size() == 0)
            idx = (idx + 1) % 8;

        pair<int, int> nodou = colas[idx].front();
        colas[idx].pop();
        total_nodos--;
        int x3 = nodou.first;
        int y3 = nodou.second;
        if(A[x3][y3] == 0)
            continue;
        // no lo he procesado
        A[x3][y3] = 0;


        if(x3 == x2 and y3 == y2)
            return;
        for(int i = -2; i <= 2; i++){
            for(int j = -2; j <= 2; j++){
                int nw_x3 = x3 + i;
                int nw_y3 = y3 + j;
                if(check(nw_x3, nw_y3)){
                    if  (  D[x3][y3] + costos[i + 2][j + 2] < D[nw_x3][nw_y3]  ){
                        D[nw_x3][nw_y3] = D[x3][y3] + costos[i + 2][j + 2];
                        colas[D[nw_x3][nw_y3] % 8].push({nw_x3, nw_y3});
                        total_nodos++;
                    }
                }
            }
        }
    }
}

int main (){

    while(cin >> n >> m and (n or m)){
        int x1, y1, x2, y2, w;
        cin >> x1 >> y1 >> x2 >> y2 >> w;

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                A[i][j] = 1, D[i][j] = 1e7;
        while(w--){
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            for(int i = a; i <= c; i++)
                for(int j = b; j <= d; j++)
                    A[i][j] = 0;
        }

        bfs_0_K(x1, y1, x2, y2);

        if(D[x2][y2] == 1e7)
            cout << "Impossible\n";
        else
            cout << D[x2][y2] << '\n';
    }



    return 0;
}
