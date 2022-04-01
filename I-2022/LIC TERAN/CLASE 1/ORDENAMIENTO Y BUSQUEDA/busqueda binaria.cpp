#include <bits/stdc++.h>
using namespace std;
const int N = 2e2;
typedef long long ll;
const ll mod = 1e9 + 7;
int A[N];


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];


    sort(A, A + n);
    for(int i = 0; i < n; i++)
        // cout << A[i] << ' ';
        printf("%3d ", A[i]);
    printf("\n");

    int x = 6;
    cin >> x;
    for(int i = 0; i < n; i++)
        printf("%3c ", ((A[i] <= x) ? 'V' : 'F'));
    printf("\n");
    
    for(int i = 0; i < n; i++)
        // cout << A[i] << ' ';
        printf("%3d ",i);
    printf("\n");

    int a = 0, b = n, mid;

    while(b - a > 1){ 
        mid = (a + b) / 2;
        if(A[mid] <= x)
            a = mid;
        else
            b = mid;
    }

    cout << "posicion donde termina a = " << a << endl;
    cout << (A[a] == x ? "SI ESTA" : "NO ESTA") << '\n';



    


    return 0;
}
