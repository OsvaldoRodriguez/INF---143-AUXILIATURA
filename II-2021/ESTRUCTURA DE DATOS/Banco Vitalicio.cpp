#include <bits/stdc++.h>

using namespace std;

int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // c++ heap (cola de prioridad) es de maximos
    int n, m, p;

    while(cin >> n >> m >> p){
        priority_queue< pair<int, char> > q;

        while(n--){
            int t;
            char op;
            cin >> t >> op;
            q.push({ -t , op });
        }

        int tiempo = -q.top().first;

        while(not q.empty()){
            tiempo += p;
            if(tiempo <= m)
                cout << tiempo << '\n';
            else
                cout << "Mil disculpas, regrese mañana\n";
            
            q.pop();
        }
    }

    return 0;
}
