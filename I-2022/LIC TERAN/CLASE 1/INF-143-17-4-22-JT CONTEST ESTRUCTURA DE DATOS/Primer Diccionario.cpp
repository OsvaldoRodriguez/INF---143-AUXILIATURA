#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
const ll mod = 1e9 + 7;

bool go(char x){
    return x >= 'a' and x <= 'z';
}

int main(){
        
    string str;
    set<string> s; // estructura de datos
    // mantiene elementos unicos y ordenados
    while(getline(cin, str)){ // hasta fin de archivo

        for(int i = 0; i < (int) str.size(); i++){
            str[i] = tolower(str[i]);
        }

        for(int i = 0; i < (int) str.size(); i++){
            string aux = "";
            while(i < (int) str.size() and go(str[i])){
                aux += str[i++];
            }
            if(aux.size() > 0)
                s.insert(aux); // insersion en el set es log n
        }
    }

    for(string i : s){
        cout << i << '\n';
    }
    return 0;
}
