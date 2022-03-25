#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
typedef long long ll;
const ll mod = 1e9 + 7;
int A[N];
int copia[N];

void merge_sort(int l, int r){ // O(n log n)
    cout <<  "merge_sort( " << l <<  ", " << r << ")\n";
    if(l == r)
        return;

    int m = (l + r) / 2;
    // hijo izquierdo
    // cout << "hijo izquiedo " ;
    merge_sort(l, m);
    
    // hijo derecho

    // cout << "hijo derecho " ;
    merge_sort(m + 1, r);

    // sacar la copia

    for(int i = l; i <= r; i++)
        copia[i] = A[i];

    // 
    // puntero del hijo izquierdo
    int L = l;
    // puntero del hijo derecho
    int R = m + 1;
    for(int i = l; i <= r; i++){
        // verificar si el hijo izquierdo tiene elementos
        if(L > m){ // ya no tiene elementos el hijo  izquierdo
            A[i] = copia[R++];
        }else if(R > r){ // el hijo derecho ya no tiene elementos
            A[i] = copia[L++];
        }else{ // ambos hijos tienen elementos
            if(copia[L] <= copia[R]){
                A[i] = copia[L++];
            }else{
                A[i] = copia[R++];
            }
        }
    }
}

void burbuja(int n){
    // Complejidad es O(n^2)
    // algoritmo de ordenamiento burbuja
    for(int i = 0; i < n - 1; i++){                  
        for(int j = i + 1; j < n; j++){             
            if(A[i] > A[j]){                        
                swap(A[i], A[j]);                   
            }
        }
    }
}
int main(){
    // Tengo un vector A de n elementos, y quiero ordenar acendentemente    
    // n <= 100000


    int n = 10;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];



    //             T(5)                T(10)
    // a < b     a = [1, 100]  , a = [1, 1000000]

    // int aux = A[i];
    // A[i] = A[j];
    // A[j] = aux;

    // burbuja
    // burbuja(n);

    // merge sort
    // cout << "ordenando con merge_sort\n";
    merge_sort(0, n - 1);
    // muestra el vector
    for(int i = 0; i < n; i++){
        cout << "A[" << i << "] = " << A[i] << "\n";
    }


    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    
    return 0;
}
