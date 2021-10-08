/// jv.umsa.bo
// https://jv.umsa.bo/problem.php?id=2145

#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;
int A[N];

int main(){

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];


    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i < j and A[i] > A[j]){
                ans++;
            }
        }
    }

    // Complejidad O(n^2)   

    /*
        n ^ 2  = (10 ^ 5) ^ 2 = 10^10  

        tiempo de ejecucion

        10^10
        ------- = 100 s   (TLE)
        10^8

    */

    cout << ans << '\n';

    return 0;
}
