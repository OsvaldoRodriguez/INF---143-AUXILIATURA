#include <bits/stdc++.h> // java.util.*
using namespace std;
typedef long long ll;
const int N = 2e7 + 5;

int divisores[] = {2, 3, 5, 7};
int potencias[] = {0, 0, 0, 0};



int main(){


    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin >> n;
    for(int i = 0; i < 4; i++){     
        while(n % divisores[i] == 0){      
            n /= divisores[i];
            potencias[i]++;
        }
    }

    if(n > 1)
        cout << -1 << '\n';
    else{
        int respuesta = 0;
        for(int i = 0; i < 4; i++)
            respuesta += potencias[i];

        cout << respuesta << '\n';
    }
    
    return 0;
}
 
 
