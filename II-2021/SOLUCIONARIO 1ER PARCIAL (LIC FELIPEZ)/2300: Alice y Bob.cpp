//https://jv.umsa.bo/problem.php?id=2300

#include <bits/stdc++.h>
  
using namespace std;
  
const int N = 2 * 1e5 + 5;
typedef long long ll;
const ll mod = 1e9 + 7;
char A[20][20];
int n, m;
bool backtraking(int x, int y, int k){
  
    if(k < 0 or x >= n or y >= m or A[x][y] == '#')
        return false;
    if(A[x][y] == 'C'){
        return true;
    }
  
    int ans = false;
  
    ans |= backtraking(x + 1, y, k - 1);
    ans |= backtraking(x, y + 1, k - 1);
    return ans;
  
  
}
int main(){
  
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    while(cin >> n >> m >> k){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                cin >> A[i][j];
            }
        bool flag = backtraking(0, 0, k);
        if(flag)
            cout << "Intentalo Bob\n";
        else
            cout << "Descansa Bob\n";
    }    
  
    return 0;
  
}
