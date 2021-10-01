#include <bits/stdc++.h>
using  namespace std;
/*
La solucion es simulacion del problema

*/



string bin(int x){
    string ans = "";
    while(x){
        string dig = to_string(x % 2);
        ans = dig + ans;
        x /= 2;
    }
    return ans;
}

string binr(int x){
    if(x == 0)
        return "";

    string dig = to_string(x % 2);
    return binr(x / 2) + dig;
}

string completar(int valor){
    if(valor == 0)
        return "";
    return "0" + completar(valor - 1);
}   



long long f1(string &A, string &B, int pos, long long pot){
    // cout << pos << " " << pot << endl;
    if(pos == -1)
        return 0;
    long long aux = 0;
    if(A[pos] == '1' || B[pos] == '1')
        aux = pot;
    return aux + f1(A, B, pos - 1, pot * 2LL); 
}

long long f2(string &A, string &B, int pos, long long pot){
    // cout << pos << " " << pot << endl;
    if(pos == -1)
        return 0;
    long long aux = 0;
    if(A[pos] == '1' && B[pos] == '1')
        aux = pot;
    return aux + f2(A, B, pos - 1, pot * 2LL); 
}

long long f3(string &A, string &B, int pos, long long pot){
    // cout << pos << " " << pot << endl;
    if(pos == -1)
        return 0;
    long long aux = 0;
    if(A[pos] == '1' && B[pos] == '0')
        aux = pot;
    return aux + f3(A, B, pos - 1, pot * 2LL); 
}

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int a, b;
    while(cin >> a >> b){
        string a1 = binr(a);
        string b1 = binr(b);
        string A = completar(31 - (int)a1.size()) + a1;
        string B = completar(31 - (int)b1.size()) + b1;
        // cout << A << "\n" << B <<  "\n";
        cout << f1(A, B, A.size() - 1, 1LL) << ' ';
        cout << f2(A, B, A.size() - 1, 1LL) << ' ';
        cout << f3(A, B, A.size() - 1, 1LL) << '\n';


    }

}
