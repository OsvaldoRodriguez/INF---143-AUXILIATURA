#include <bits/stdc++.h>

using namespace std;

int sum(string &b){
    int ans = 0;
    for(int i = 0; i < (int) b.size(); i++){
        if(b[i] >= '0' and b[i] <= '9')
            ans += (b[i] - '0');
    }
    return ans;
}

bool cmp(string &a, string &b){
    int ta = (int) a.size();
    int tb = (int) b.size();
    if(ta == tb){
        ta = sum(a);
        tb = sum(b);
        if(tb == ta){
            return a < b;
        }
        return ta < tb;
    }
    return ta < tb;
}

int main(){
    string str;
    while(getline(cin, str)){
        int n = (int) str.size();
        vector<string> arr;
        for(int i = 0; i < n; i++){
            string aux = "";
            while(i < n and str[i] != ' ')
                aux += str[i++];

            arr.push_back(aux);
        }
        sort(arr.begin(), arr.end(), cmp);

        for(int i = 0; i < (int) arr.size(); i++)
            cout << arr[i] << " ";
        cout << '\n';

    }
    return 0;
}
