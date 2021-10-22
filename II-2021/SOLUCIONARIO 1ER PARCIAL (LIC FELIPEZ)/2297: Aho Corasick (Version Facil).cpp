//https://jv.umsa.bo/problem.php?id=2297
#include <bits/stdc++.h>
 
using namespace std;
typedef pair<int, string> is;
const int N = 1e2 + 10;
typedef tuple<int, string, int> isi;
int ANS[N][N];
bool go(int pos, const string &p, const string &t){
    for(int i = 0; i < (int) p.size(); i++){
        if(p[i] != t[pos++])
            return false;
    }
    return true;
}
 
bool cmp(isi A, isi B){
    int a1, b1, a3, b3;
    string a2, b2;
    tie(a1, a2, a3) = A;
    tie(b1, b2, b3) = B;
    if(a1 == b1)
        return a2 < b2;
    return a1 > b1;
}
isi A[N];
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string t, p;
    int q;
    cin >> t >> q;
    for(int i = 0; i < q; i++){
        cin >> p;
        ANS[i][0] = 0;
        int k = 1;
        for(int j = 0; j < t.size() - p.size() + 1; j++){
            if(go(j, p, t)){
                ANS[i][k++] = j;
                ANS[i][0]++;
            }
        }
        A[i] = tie(ANS[i][0], p, i);
    }
    sort(A, A + q, cmp);
    for(int i = 0; i < q; i++){
        int a1, a3;
        string a2;
        tie(a1, a2, a3) = A[i];
        cout << a2 << " " << a1 << '\n';
        int k = ANS[a3][0];
        for(int j = 1; j <= k; j++){
            cout << ANS[a3][j];
            if(j + 1 <= k)
                cout << ' ';
        }
        cout << '\n';
    }
 
    return 0;
 
}
