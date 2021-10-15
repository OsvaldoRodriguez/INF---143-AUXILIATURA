#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

typedef long long ll;

int main(){

    // lectura rapida
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // a * b   -> a, b <= 10^15 
    // 10^30    -> 10^36 

    /*
        ARITMETICA MODULAR

        (a + b) % m = (a % m + b % m) % m;
        (a - b) % m = (a % m - b % m + m) % m;
        (a * b) % m = (a % m * b % m) % m;
        (a / b) % m = (a % m * b^-1 % m) % m

        (a / b) % m = (a % m * pow(b, m - 2, m) % m) % m
        siempre que m es primo

        inverso modular
        a^-1 % m

        existe si a y m son coprimos
        gcd(a, m) == 1
        
        a * a^-1 = 1


        https://es.wikipedia.org/wiki/Inverso_multiplicativo_(aritm%C3%A9tica_modular)


        pow(a, m - 2, m)


        

    */


    ll a = 2343849334394833;
    ll b = 2394830928340984;
    ll m = 10007;
    ll ans = (a % m * b % m) % m;
    cout << ans << '\n';



    return 0;
}
