#include <bits/stdc++.h>

using namespace std;
int d;
bool ok(string &a){
    vector<int> fre(26, 0);
    for(char i : a){
        if(i == ' ')
            continue;
        fre[i - 'A']++;
    }

    int mx = max_element(fre.begin(), fre.end()) - fre.begin();
    int cnt = 0;
    d = abs(5 - mx) + 1;
    // cout << char(mx + 'A') << '\n';
    for(int i = 0; i < 26; i++){
        cnt += (fre[mx] == fre[i]);
    }
    return cnt == 1;
}
int main(){
    string str;
    int t;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;   
    cin.ignore();
    while(t--){
        string str;
        getline(cin, str);
        if(ok(str)){
            cout << d << " ";
            for(char i : str){
                if(i == ' ')
                    cout << i;
                else{
                    int ascci = i - 'A';
                    ascci = (ascci - d + 26) % 26;
                    cout << char(ascci + 'A');
                }
            }
            cout << '\n';
        }else
            cout << "NOT POSSIBLE\n";
    } 
    return 0;
}
