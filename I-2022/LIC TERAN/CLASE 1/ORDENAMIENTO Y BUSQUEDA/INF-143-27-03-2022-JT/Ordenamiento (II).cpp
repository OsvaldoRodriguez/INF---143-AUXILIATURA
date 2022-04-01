// link https://jv.umsa.bo/problem.php?cid=2400&pid=2

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
typedef long long ll;
const ll mod = 1e9 + 7;
 
 
pair<int, string> A[N];
pair<int, string> copia[N];
 
bool cmp(pair<int, string> X, pair<int, string> Y){
    // X = (2, $aa)
    // Y = (2, $ab)
 
    if(X.first == Y.first){
        // comparar por el 2do parametro
 
        if(X.second[1] == Y.second[1]){
            // comparar por el 3er parametro
            return X.second[2] < Y.second[2];
        }else{
            return X.second[1] > Y.second[1];
        }
 
 
    }else{
       return X.first < Y.first; // ascendentemente 
    }
}
 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
 
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i].first >> A[i].second;
    }
    // merge_sort(0, n - 1);
 
 
 
    sort(A, A + n, cmp);
 
    for(int i = 0; i < n; i++)
        cout << A[i].first << " " << A[i].second << '\n';
 
 
 
    return 0;
}
