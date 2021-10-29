#include <bits/stdc++.h>

using namespace std;

int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string str;
    while(getline(cin, str)){
        int n = (int) str.size();
        stack<int> pila;

        bool flag = true;
        for(int i = 0; i < n; i++){
            string aux = "";
            while(i < n && str[i] != ' ')
                aux += str[i++];

            if(aux[0] == '-' or (aux[0] >= '1' and aux[0] <= '9')){
                int numero = atoi(aux.data());
                if(numero < 0)
                    pila.push(abs(numero));
                else{
                    if(pila.size() == 0){
                        flag = false;
                    }else{
                        if(numero != pila.top()){
                            flag = false;
                        }else
                            pila.pop();
                    }
                }
            }

        }

        if(flag and pila.empty())
            cout << "No defectuoso\n";
        else
            cout << "Defectuoso\n";

    }

    return 0;
}
