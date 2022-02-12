// ID: 2013 problema juez patito
#include <bits/stdc++.h> // java.util.*;
using namespace std;
 
int go(string a){
    int cnt = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != ' ')
            cnt++;
    }
 
    return cnt;
}
 
bool f(char a, char b){
    int aa = a - '0';
    int bb = b - '0';
    return (aa + bb) == 7;
}
 
 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     
 
    string a, b, c, d;
 
    while(getline(cin, a)){
        if(a != ""){
            getline(cin, b);
            getline(cin, c);
            getline(cin, d);
 
            // codigo para el problema
            string ans = "Mal";
 
            bool flag = f(a[2], c[2]) && f(b[2], d[2]);
            if(go(a) == 3){
                if(f(a[0], a[4]) && flag)
                    ans = "Bien";
            }else if(go(b) == 3){
                if(f(b[0], b[4]) && flag)
                    ans = "Bien";
            }else if(go(c) == 3){
                if(f(c[0], c[4]) && flag)
                    ans = "Bien";
            }else if(go(d)== 3){
                if(f(d[0], d[4]) && flag)
                    ans = "Bien";
            }
            cout << ans << '\n';
        }
 
    }
 
    return 0;
}
