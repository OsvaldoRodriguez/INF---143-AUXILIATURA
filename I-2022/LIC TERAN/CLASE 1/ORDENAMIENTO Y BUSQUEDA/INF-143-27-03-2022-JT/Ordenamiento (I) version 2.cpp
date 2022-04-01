// link https://jv.umsa.bo/problem.php?cid=2400&pid=0

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
typedef long long ll;
const ll mod = 1e9 + 7;
 
 
pair<int, string> A[N];
pair<int, string> copia[N];
 
void merge_sort(int l, int r){ // O(n log n)
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
 
            pair<int, string> X = copia[L];
            pair<int, string> Y = copia[R];
 
            if(X.first == Y.first){
                // comparar por el segundo valor
                if(X.second >= Y.second){
                    A[i] = X;
                    L++;
                }else{
                    A[i] = Y;
                    R++;
                }
            }else{
                if(X.first <= Y.first){
                    A[i] = X;
                    L++;
                }else{
                    A[i] = Y;
                    R++;
                }
            }
        }
    }
}
 
bool comparador(pair<int, string> X, pair<int, string> Y){
    if(X.first == Y.first)
        return X.second > Y.second;
    return X.first < Y.first;
}
 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
 
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i].first >> A[i].second;
    }
    // merge_sort(0, n - 1);
 
 
 
    sort(A, A + n, comparador);
     
    for(int i = 0; i < n; i++)
        cout << A[i].first << " " << A[i].second << '\n';
 
 
 
    return 0;
}
