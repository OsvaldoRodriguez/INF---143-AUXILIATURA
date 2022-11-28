#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5;
ll dp[N];
ll dp2[3];
ll f(int n){
	if(n <= 1)
		return n;
		
	if(dp[n] != -1)
		return dp[n];
	
	return dp[n] = f(n - 2) + f(n - 1);
}


void iterativo(int n){
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
		
	
	cout << dp[n] << "\n";
	
}

void iterativo2(int n){
	dp2[0] = 0;
	dp2[1] = 1;
	for(int i = 2; i <= n; i++)
		dp2[i % 3] = dp2[(i - 1) % 3] + dp2[(i - 2) % 3];
		
	
	cout << dp2[n % 3] << "\n";
	
}

void iterativo3(int n){
	ll a = 0;
	ll b = 1;
	ll c;
	for(int i = 2; i <= n; i++){
		c = a + b;
		a = b;
		b = c;
	}
	
	cout << c << endl;
		
	
	cout << dp2[n % 3] << "\n";
	
}


int main() {
	ll n;
	cin >> n;
	memset(dp, -1,sizeof dp);
	cout << f(n) << "\n";
	iterativo(n );
	iterativo2(n );
	iterativo3(n );
	return 0;
}
