#include <bits/stdc++.h> // java.util.*
using namespace std;
typedef long long ll;
const int N = 20 + 5;

char A[10][10];

bool camino[10][10];
int n, m;
vector<string> direccion;

// vector de direcciones
int dx[] = {1, 0}, dy[] = {0, 1};
vector<string> dir = {"A", "D"};

void backtraking(int fila, int columna){
    // caso base
    if(fila == n - 1 && columna == m - 1){
        camino[0][0] = 1;

        cout << "camino: ";
        for(int i = 0; i < (int) direccion.size(); i++)
            cout << direccion[i];

        cout << '\n';
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                cout << camino[i][j];
            cout << '\n';
        }

        cout << '\n';
        return;
    }

    

    // ir abajo


    for(int i = 0; i < 2; i++){
        int nw_fila = fila + dx[i];
        int nw_columna = columna + dy[i];
        if(nw_fila < n && nw_columna < m && A[nw_fila][nw_columna] == '.'){
            camino[nw_fila][nw_columna] = true;
            direccion.push_back(dir[i]);
            backtraking(nw_fila, nw_columna);
            camino[nw_fila][nw_columna] = false;
            direccion.pop_back();
        }
    }
    // arriba

    // izquierda
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m ; j++)
            cin >> A[i][j];


    backtraking(0, 0);
    // bool ans = backtraking(0, 0);
    // cout << ans << '\n';
    

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    
    return 0;
}
 
 
