//https://jv.umsa.bo/problem.php?cid=2426&pid=10
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 550;
const ll mod = 1e9 + 7;
int n;
int v[15];

int ans;
void subset(int i){
    if(i == n){
        int cnt = 0;
        for(int i = 1; i < n - 1; i++){
            if(((v[i] > v[i - 1] and v[i] > v[i + 1]) or (v[i] < v[i - 1] and v[i] < v[i + 1]) )){
                cnt++;
            }
        }
        ans += cnt;
        return;
    }
    for(int j = 0; j < 3; j++){
        v[i] = j;
        subset(i + 1);
    }
}

int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int casos;
    cin >> casos;
    while(casos--){
        cin >> n;
        ans = 0;
        subset(0);
        cout << ans << '\n';
    }
    return 0;
 
}
