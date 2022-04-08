// link https://jv.umsa.bo/problem.php?cid=2404&pid=5

// usar el teorema de pick
// Formula de Gauss (area de poligonos)

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N = 1e3 + 10;
const ll mod = 1e9 + 7;
 
 
double go(int x, int y, int x1, int y1){
    return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
}
 
int X[40], Y[40];
int main(){
     
    int n;
 
 
    while(cin >> n){
 
        for(int i = 0; i < n; i++)
            cin >> X[i] >> Y[i];
 
        double area = 0;
        for(int i = 0; i < n; i++){
            double A1 = X[i] * Y[(i + 1) % n];
            double A2 = Y[i] * X[(i + 1) % n];
            area = area + (A1 - A2);
        }
        area /= 2;
        int punto_borde = n;  
 
        for(int i = 0; i < n; i++){
            int A1 = abs(X[i] - X[(i + 1) % n]);
            int A2 = abs(Y[i] - Y[(i + 1) % n]);
            // __gcd(A1, A2) es los puntos en medio de dos vertices
            punto_borde += __gcd(A1, A2) - 1;
        }
 
        cout << fixed << setprecision(1) << area << "\n";
 
        cout << punto_borde << "\n";
 
 
        // B = puntos en el borde
 
        int punto_interior = (int) area - punto_borde / 2 + 1;
        cout << punto_interior << "\n";
    }
    return 0;
}
