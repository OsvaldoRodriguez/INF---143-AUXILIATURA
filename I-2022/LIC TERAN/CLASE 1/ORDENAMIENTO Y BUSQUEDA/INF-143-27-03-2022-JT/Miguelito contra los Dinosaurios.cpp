//link https://jv.umsa.bo/problem.php?cid=2400&pid=8

#include <bits/stdc++.h>
using namespace std;
const int N = 2e4;
typedef long long ll;
const ll mod = 1e9 + 7;
int A[N];
int ACC[N];

// tiene un algoritmo -> hacerlo mas rapido

// -> generalmente se aumenta el consumo de memeoria


// -> tiempo -> memoria
// -> memoria por tiempo

void preprocesar(){
    ACC[0] = A[0];
    for(int i = 1; i < N; i++)
        ACC[i] = ACC[i - 1] + A[i];
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];


    sort(A, A + n);
    preprocesar();
    int q;
    cin >> q;

    // O(q log n)  
    while(q--){   
        int x;
        cin >> x;
        int a = 0, b = n, mid;
        while(b - a > 1){
            mid = (a + b) / 2;
            if(A[mid] <= x)
                a = mid;
            else
                b = mid;
        }


        cout << a + 1 << ' ' << ACC[a] << '\n';
        
    }


    return 0;
}
