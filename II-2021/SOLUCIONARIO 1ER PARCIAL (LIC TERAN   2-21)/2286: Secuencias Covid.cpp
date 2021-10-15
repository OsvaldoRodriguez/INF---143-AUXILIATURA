#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int A[N];

bool ok(int pos, string texto, string patron){
    int cur = pos;
    int i;
    for(i = 0; i < (int)patron.size() && pos < (int) texto.size(); i++){
        if(patron[i] != texto[pos++])
            return false;
    }
    return true;
}
int main(){

    // lectura rapida
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string texto, patron;
    cin >> patron >> texto;
    int pos = 0;
    for(int i = 0; i < (int) texto.size() - (int) patron.size() + 1; i++){
        if(ok(i, texto, patron)){
            A[pos++] = i;
        }
    }

    for(int i = 0; i < pos; i++){
        cout << A[i];
        if(i + 1 < pos )
            cout << ' ';
    }


    return 0;
}
