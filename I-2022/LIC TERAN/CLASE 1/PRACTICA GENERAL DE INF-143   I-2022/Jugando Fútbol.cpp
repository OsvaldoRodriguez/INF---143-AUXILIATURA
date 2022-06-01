#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> A(n), B(n);

    for(int &i : A)
        cin >> i;

    for(int &i : B)
        cin >> i;

    // (num, den)
    map<pair<int, int>, int> m;

    int ans = 0;
    for(int i = 0; i < n; i++){
        int num = -B[i];
        int den = A[i];
        int gcd = __gcd(num, den);
        if(A[i] != 0){
            num /= gcd;
            den /= gcd;
            m[{num, den}]++;
        }
        if(A[i] == 0 and B[i] == 0)
            ans++;
    }
    int mx = 0;
    for(auto i : m){
        mx = max(mx, i.second);
    }
    cout << mx + ans << '\n';
    return 0;
}
