//https://jv.umsa.bo/problem.php?cid=2426&pid=9

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 550;
const ll mod = 1e9 + 7;
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int casos;
    cin >> casos;
    while(casos--){
        int n, x;
        cin >> n;
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> x;
            sum += x;
        }

        if(sum % n == 0)
            cout << "0\n";
        else
            cout << "1\n";
    }
    return 0;
 
}
