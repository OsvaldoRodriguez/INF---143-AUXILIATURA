#include <bits/stdc++.h> // java.util.*
using namespace std;
typedef long long ll;
const int N = 100000 + 5;


int criba[N];
vector<int> primos;
int fre[N];

void CRIBA(){
    // todo en true (1)

    for(int i = 0; i < N; i++)
        criba[i] = 1;

    // i < sqrt(n) = i * i < n
    for(int i = 2; i * i < N; i++){
        if(criba[i] == 1){
            for(int j = i + i; j < N; j += i){
                criba[j] = 0;
            }
        }
    }


    for(int i = 2; i < N; i++){
        if(criba[i] == 1){
            primos.push_back(i);
        }
    }
}



/*

Criba es una tecnica para hallar numeros primeros de 1 a N

O(n log log n)

*/




int main(){


    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    CRIBA();

    // 
    for(int i = 0; i < (int) primos.size(); i++){
        int suma = 0;
        for(int j = i; j < (int) primos.size(); j++){
            suma += primos[j];
            if(suma < N){
                fre[suma]++;
            }
        }
    }


    int x;
    while(cin >> x){
        cout << fre[x] << '\n';
    }
    
    // operaciones
    
    return 0;
}
 
 
