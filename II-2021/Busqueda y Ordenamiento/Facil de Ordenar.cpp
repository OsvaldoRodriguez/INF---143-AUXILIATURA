// https://jv.umsa.bo/problem.php?id=1631
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int main(){
  ios_base::sync_with_stdio(0); 
  cin.tie(0); 
  cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    	int n;
    	string str;
    	cin >> str >> n;
    	int fre[260];
    
    	for(int i = 0; i < 260; i++){
        fre[i] = i;
      }
      while(n--){
        char x;
        int ascci;
        cin >> x >> ascci;
        fre[x] = ascci;
      }
    	pair<int, char> A[str.size()];
    	for(int i = 0; i < str.size(); i++){
        A[i] = {fre[str[i]], str[i]};
      }
    	sort(A, A + str.size());
    	for(int i = 0; i < str.size(); i++){
        cout << A[i].second;
      }
    	cout << "\n";
    
  }
  
	return 0;
  
}
