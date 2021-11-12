#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;
int coin[] = {1, 3, 4};
int k = 3;

int dp[N];


// cantidad de estados (memorizados) * transicion

// n * k

// dp Coin change O(k * n)


/*




button up  -> iterativo (mas dificil de ver)
    - es mas rapido
    - si importa el orden
    - se puede eliminar una dimension (depende de la transicion)



top down  -> recursivo (mas intuitivo)

    - es mas lento (recursion)
        - el orden de estados no importa

*/
int backtraking(int n){

    // caso base
    if(n == 0)
        return 0;

    int ans = dp[n];
    // negativo sig no calculado

    if(ans != -1){// ya esta calculado
        return dp[n];
    }
    
    ans = 1e9;
    for(int i = 0; i < k; i++){
        if(n >= coin[i]){
            ans = min(ans, backtraking(n - coin[i]) + 1);
        }
    }
    dp[n] = ans;
    return ans;

}


int main(){

    int n = 6;
    cin >> n;

    // llenar en -1

    memset(dp, -1, sizeof dp);
    // 0, 1


    int ans = backtraking(n);
    cout << ans << '\n';
    return 0;
}
