#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
const ll mod = 1e9 + 7;

bool go(char x){
    return x >= 'a' and x <= 'z';
}

int main(){
        
    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;
        int tiempo = 0;
        // (tarea, indice)
        deque<pair<int, int>> p;
        // max heap
        // guarda elementos en orden (mayor a menor)
        // solo puedo eliminar el mas grande
        priority_queue<int> q;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            p.push_back({x, i});
            q.push(x);
        }

        // for(auto i : p)
        //     cout << i.first << " " << i.second << endl;

        while(p.size() > 0){
            pair<int, int> tmp = p.front();
            p.pop_front();
            if(tmp.second == m){
                if(q.size() and q.top() <= tmp.first)
                    break;
                else
                    p.push_back(tmp);
            }else{
                if(q.size() and q.top() == tmp.first){
                    tiempo++;
                    q.pop();
                }else
                    p.push_back(tmp);
            }

        }

        cout << tiempo + 1 << '\n';

    }
    return 0;
}
