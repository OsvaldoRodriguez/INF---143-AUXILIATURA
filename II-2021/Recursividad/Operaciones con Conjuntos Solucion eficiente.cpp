#include <bits/stdc++.h>
using  namespace std;

/*
Con manipulacion de bits

*/
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int a, b;
    while(cin >> a >> b){
        cout << (a | b) << " " << (a & b) << " " << (a & (~b)) << '\n';
    }

}
