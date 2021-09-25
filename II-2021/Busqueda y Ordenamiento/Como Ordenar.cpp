// https://jv.umsa.bo/problem.php?id=1211
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

ll f(ll x){
  ll fact = 1;
  for(int i = 1; i <= x; i++){
    fact = (fact % mod * i % mod) % mod;
  }
  return fact;
}
int main(){
  
  
	// ARIMETICA MODULAR
  
  /*
  	(a + b) % mod = (a % mod + b % mod) % mod;
    (a - b) % mod = (a % mod - b % mod + mod) % mod;
    (a * b) % mod = (a % mod * b % mod) % mod;
    (a / b) % mod = (a % mod * inverso_modular(b) % mod) % mod;
    
    inverso_modular(b)  = pow(b, euler(mod) - 1, mod);
    // cuando mod es primo euler(n) = n - 1
    inverso_modular(b) = pow(b, mod - 1 - 1, mod) = pow(b, mod - 2, mod);
    // cuando mod no es primo, mod - 2, se usa la funcion de euler    euler(mod) - 1
  
  	n = 5  -> euler(n) = n - 1
    
    1 2 3 4 5
    
    
    1, 2, 3, 4  -> 4
  
  */
  
	int n;
  cin >> n;
  int A[n + 5];
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }
  
  sort(A, A + n); // ordenando todo el vector

  int cnt = 1;
  ll ans = 1;
  for(int i = 1; i < n; i++){
    if(A[i] == A[i - 1]){
      cnt++;
    }else{
      ans = (ans % mod * f(cnt) % mod) % mod;
      cnt = 1;
    }
  }
  if(cnt > 1){
    ans = (ans % mod * f(cnt) % mod) % mod;
  }
  
  cout << ans << '\n';
  
}
