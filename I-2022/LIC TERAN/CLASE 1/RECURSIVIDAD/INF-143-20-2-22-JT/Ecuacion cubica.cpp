#include <bits/stdc++.h> // java.util.*
using namespace std;
typedef long long ll;
const int N = 20 + 5;



int main(){


    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){

        int c;
        cin >> c;

        set<pair<int, int>> s;
        for(int l = 1; l <= 50; l++){
            for(int n = 1; n <= 50; n++){
                for(int m = 1; m <= 50; m++){
                    // calcular b;
                    int x = l * m * n;
                    int raiz = sqrt(x);

                    if(raiz * raiz == x && l + m + n == c){
                        int a = l * m + l * n + n * m;
                        s.insert({a, raiz});
                    }
                }
            }
        }

        for(auto i : s){
            cout << "(" << i.first << ", " << i.second << ")";
        }
        cout << '\n';
    }

    return 0;
}
 
 
