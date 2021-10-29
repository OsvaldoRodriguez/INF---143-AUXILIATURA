#include <bits/stdc++.h>

using namespace std;

int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    char ope;
    int valor;

    // heap max
    priority_queue<int> q;
    while(cin >> ope && ope != 'T'){
        if(ope == 'S'){
            cin >> valor;
            q.push(valor);
        }else if(ope == 'I' or ope == 'D'){
            cin >> valor;
            if(q.size() > 0){
                int mayor = q.top();
                if(ope == 'D')
                    valor *= -1;
                mayor += valor;
                q.pop();
                q.push(mayor);
            }else
                cout << "Error\n";
        }else if(ope == 'A'){
            if(q.size() > 0)
                cout << q.top() << '\n';
            else
                cout << "Error\n";
        }else if(ope == 'R'){
            if(q.size() > 0)
                q.pop();
            else
                cout << "Error\n";
        }
    }

    return 0;
}
