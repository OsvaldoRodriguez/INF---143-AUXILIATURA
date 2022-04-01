// link https://jv.umsa.bo/problem.php?cid=2400&pid=7

#include <bits/stdc++.h>
using namespace std;
const int N = 2e2;
typedef long long ll;
const ll mod = 1e9 + 7;
int A[N];
 
 
int sd(int x){
    int suma = 0;
    while(x){
        suma += x % 10;
        x /= 10;
    }
    return suma;
}
 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];
 
    for(int i = 0; i < n - 1; i ++){
        for(int j = i + 1; j < n; j++){
            int sd1 = sd(A[i]);
            int sd2 = sd(A[j]);
            if(sd1 == sd2){
                // comparar por el menor
                if(A[j] < A[i]){
                    swap(A[j], A[i]);
                }
            }else{
                if(sd2 < sd1){
                    swap(A[i], A[j]);
                }
            }
        }
    }
 
    cout << A[0];
    for(int i = 1; i < n; i++)
        cout << " " << A[i];
    cout << '\n';
     
    return 0;
}
