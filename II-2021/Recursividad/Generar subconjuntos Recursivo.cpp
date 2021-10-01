#include <bits/stdc++.h>
using  namespace std;
int A[20];
bool estado[20];
int n;

void subsets(int i){
    if(i == n){
        cout << "{ ";

        int suma = 0;
        for(int i = 0; i < n; i++){
            if(estado[i] == true){
                cout << A[i] << ' ';
            }
        }
        cout << "}\n";

        // aqui va el codigo
        

        return;
    }

    estado[i] = true;
    subsets(i + 1);
    estado[i] = false;
    subsets(i + 1);
}
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    while(cin >> n){
        for(int i = 0; i < n; i++)
            cin >> A[i];
        subsets(0); 


    }

}
