// link https://jv.umsa.bo/problem.php?cid=2404&pid=2

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N = 1e3 + 10;
const ll mod = 1e9 + 7;
int maquinas[105];

int f(int tiempo, int n){
    int cantidad_trabajos = 0;
    for(int i = 0; i < n; i++)
        cantidad_trabajos += tiempo / maquinas[i];

    return cantidad_trabajos;
}
int main(){
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> maquinas[i];

    int consultas;
    cin >> consultas;
    int trabajos; 
    while(consultas--){
        cin >> trabajos;
        int a = 0, b = 1e5, mid;
        while(b - a > 1){
            mid = (a + b) / 2;
            // cout << a << " " << b << " " << mid  << " " << f(mid, n) << endl;
            if(f(mid, n) >= trabajos)
                b = mid;
            else
                a = mid;
        }
        cout << "Tiempo minimo para " << trabajos << " trabajos es: ";
        cout << b << "\n";

    }


    return 0;
}
