#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;
int A[N];
int copia[N];

void merge_sort(int l, int r){
    if(l == r){
        return;
    }
    // hijo izquierdo
    int m = (l + r) >> 1; // (l + r) / 2;
    // cout << "hijo izquierdo\n";
    merge_sort(l, m);
    // cout << "hijo derecho\n";
    merge_sort(m + 1, r);

    for(int i = l; i <= m; i++)
        copia[i] = A[i];

    for(int i = m + 1; i <= r; i++)
        copia[i] = A[i];

    int L = l; // puntero hijo izquierdo
    int R = m + 1; // puntero hijo derecho

    // reconstruyendo el padre (por su hijo izquierdo y derecho)
    for(int i = l; i <= r; i++){
        if(L <= m and R > r){ // solo el hijo izquierdo tiene elmeentos
            A[i] = copia[L];
            L++;
        }else if(R <= r and L > m){
            A[i] = copia[R];
            R++;
        }else{
            if(copia[L] <= copia[R]){
                A[i] = copia[L];
                L++;   
            }else{
                A[i] = copia[R];
                R++;
            }
        }
    }
}


int main(){

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];


    merge_sort(0, n - 1);
    for(int i = 0; i < n; i++){
        cout << "A[" << i << "] = " << A[i] << '\n'; 
    }
    
    return 0;
}
