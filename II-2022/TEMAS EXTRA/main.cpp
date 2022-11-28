#include <bits/stdc++.h>
using namespace std;


bool verificar_bit(int x, int pos){
	return (x & (1 << pos)) != 0;
}

int contar(int x){
	int c = 0;
	for(int i = 0; i < 32; i++){
		if(verificar_bit(x, i))
		c++;
	}
	return c;
}

int main() {
	
	int a = 113432;
	int b = 1123;
	
	cout << bitset<32> (a) << " \n";
	cout << bitset<32> (b) << " \n";
	
	int r = a ^ b;
	cout << bitset<32> (r) << " \n";
	
	cout << verificar_bit(a, 23) << "\n";
	cout<< " cantidad: " << contar(a) << " " << __builtin_popcount(a) << endl;
	
	int aa = 72;
	cout << bitset<32> (aa) << "\n";
	cout << bitset<32> (-aa) << "\n";
	return 0;
}
