#include <bits/stdc++.h>

using namespace std;

int main(){

    string str;
    vector<string> A;
    while(getline(cin, str)){
        A.push_back(str);
    }

    // sort(A.begin(), A.end());

    vector<int> calcular((int) A.size());
    // calcular[0] = 1;
    for(int i = 0; i < A.size(); i++){
        calcular[i] = 1;
        for(int j = 0; j < i; j++){
            if(A[j] < A[i]){
                calcular[i] = max(calcular[i], calcular[j] + 1);
            }
        }
    }


    int mx = *max_element(calcular.begin(), calcular.end());
    cout << mx << '\n';
    cout << "***\n";
    string last = "{{{{{{{{{";

    stack<string> pila;
    for(int i = A.size() - 1; i >= 0; i--){
        if(calcular[i] == mx and last >= A[i]){
            mx--;
            pila.push(A[i]);
            last = A[i];
        }   
    }
    while(not pila.empty()){
        cout << pila.top() << '\n';
        pila.pop();
    }


    return 0;
}
