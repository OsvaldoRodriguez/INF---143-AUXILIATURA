//https://jv.umsa.bo/problem.php?cid=2428&pid=1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 550;
const ll mod = 1e9 + 7;

bool vis[55][55];

char go(char dir, char girar){

    if(girar == 'L'){
        if(dir == 'N')
            dir = 'W';
        else if(dir == 'W')
            dir = 'S';
        else if(dir == 'S')
            dir = 'E';
        else
            dir = 'N';
    }else{
        if(dir == 'N')
            dir = 'E';
        else if(dir == 'E')
            dir = 'S';
        else if(dir == 'S')
            dir = 'W';
        else
            dir = 'N';
    }

    return dir;
}
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    char dir;
    int x, y;
    string str;
    for(int i = 0; i < 55; i++)
        for(int j = 0; j < 55; j++)
            vis[i][j] = true;
    while(cin >> x >> y >> dir >> str){
        bool flag = true;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == 'F'){
                int last_x = x, last_y = y;
                if(dir == 'N')
                    y++;
                else if(dir == 'S')
                    y--;
                else if(dir == 'W')
                    x--;
                else
                    x++;

                if( !(x >= 0 and x <= n and y >= 0 and y <= m) ){
                    if(vis[last_x][last_y] == true){
                        // cuando el robot sale del tabler por primera vez
                        vis[last_x][last_y] = false;
                        cout << last_x << " " << last_y << " " << dir << " LOST\n";
                        flag = false;
                        break;
                    }else{
                        x = last_x;
                        y = last_y;
                    }
                }

            }else{
                dir = go(dir, str[i]);
            }

        }
        if(flag == true)
            cout << x << " " << y << " " << dir << '\n';

    }

    return 0;
 
}
