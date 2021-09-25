// https://jv.umsa.bo/problem.php?id=1979
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 105;
int n, x, maquinas[N];

bool f(int m){
  ll trabajos = 0;
  for(int i = 0; i < n; i++){
    trabajos += m / maquinas[i];
  }
  
  return trabajos >= x;
}
int main(){
  ios_base::sync_with_stdio(0); 
  cin.tie(0); 
  cout.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> maquinas[i];
  }
  
  int consultas;
  cin >> consultas;
  while(consultas--){
    cin >> x;
    int a = 0, b = 1e8, mid;
    // a es falso
    // b es verdad
    while(b - a > 1){
      mid = (a + b) / 2;
      if(f(mid)){
        b = mid;
      }else{
        a = mid;
      }
    }
    cout << "Tiempo minimo para " << x << " trabajos es: " << b << '\n';
  }
	return 0;
  
}
