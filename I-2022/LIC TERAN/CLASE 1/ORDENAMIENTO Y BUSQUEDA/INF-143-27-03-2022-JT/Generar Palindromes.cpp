// link https://jv.umsa.bo/problem.php?cid=2400&pid=5
#include <bits/stdc++.h>
using namespace std;
const int N = 5e4;
typedef long long ll;
const ll mod = 1e9 + 7;
 
string palidromes[4 * N];
 
 
void preprocesar(){
    int idx = 0;
    palidromes[0] = "";
    palidromes[1] = "a";
    palidromes[2] = "b";
    idx = 3;
 
    // O(n)
    for(int i = 0; i < N; i++){     
        palidromes[idx++] = "a" + palidromes[i] + "a";
        palidromes[idx++] = "b" + palidromes[i] + "b";
         
    }
    // cout << idx << "\n";
 
    // O(n log n)
    sort(palidromes, palidromes + idx);
    // for(int i = 0; i < 100; i++)
    //     cout << i << " : " << palidromes[i] << endl;
}
int main(){
 
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
 
 
    preprocesar();   // n log n
    int t;
    cin >> t;
    while(t--){     // O(t)  
        int x;
        cin >> x;
        cout << palidromes[x] << '\n';
    }
    return 0;
}
