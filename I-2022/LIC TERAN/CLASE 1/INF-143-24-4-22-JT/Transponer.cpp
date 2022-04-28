// https://jv.umsa.bo/problem.php?cid=2428&pid=5

#include <bits/stdc++.h> // java.util.*;
using namespace std;
const int N = 1e5 + 100;
// (nodo, peso)
vector<pair<int ,int> > G[N];

vector<int> f(string &A){
    vector<int> B;
    for(int i = 0; i < A.size(); i++){
        string aux = "";
        while(i < A.size() and A[i] != ' ')
            aux += A[i++];

        B.push_back(atoi(aux.data()));
    }
    return B;
}

void print(vector<int> &A){
    for(int i : A)
        cout << i << ' ';
    cout << endl;
}
int main(){
    

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    string a, b;
    cin.ignore();
    for(int i = 1; i <= n; i++){
        getline(cin, a);
        vector<int> nodos = f(a);
        getline(cin, b);
        vector<int> pesos = f(b);
        for(int j = 0; j < nodos.size(); j++){
            G[nodos[j]].push_back({i, pesos[j]});
        }
    }
    cout << n << " " <<  m << '\n';
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < G[i].size(); j++){
            cout << G[i][j].first;
            if(j + 1 < G[i].size())
                cout << " ";
        }
        cout << '\n';
        for(int j = 0; j < G[i].size(); j++){
            cout << G[i][j].second;
            if(j + 1 < G[i].size())
                cout << " ";
        }
        cout << '\n';
    }

    return 0;
}

