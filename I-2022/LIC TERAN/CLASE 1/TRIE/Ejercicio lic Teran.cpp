#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
const ll mod = 1e9 + 7;
struct Trie{
    // cuantas palabras finalizan en el nodo
    int cnt;
    int final_palabras = 0;
    map<char, Trie*> m;



    Trie(){
        cnt = 0;
        m.clear();
    }

};

void adicionar(string a, Trie* raiz){
    Trie* node = raiz;
    for(int i = 0; i < a.size(); i++){
        if(node -> m[a[i]] == NULL){
            node -> m[a[i]] = new Trie();
        }

        node = node -> m[a[i]];
    }
    node -> cnt++;
}

int ans = 0;
void dfs(Trie* raiz, int final){
    // auto aux = raiz -> m;
    for(auto i : raiz -> m){
        int F = i.second -> cnt;
        int cost = 0;
        if(F > 0){
            cost = i.second -> cnt;
            ans += (final);
        }
        dfs(i.second, final + cost);
    }
}
int main(){
        
    Trie* raiz = new Trie();
    adicionar("1", raiz);
    adicionar("1", raiz);
    adicionar("1", raiz);
    adicionar("1234", raiz);
    adicionar("12", raiz);
    adicionar("12", raiz);
    adicionar("123", raiz);
    adicionar("789", raiz);
    dfs(raiz, 0);

    cout << ans << '\n';
    return 0;
}
