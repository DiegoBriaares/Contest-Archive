#include <bits/stdc++.h>
using namespace std;
#define MAX 2000009
#define ll unsigned long long
ll k,d,t,aux;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>k>>d>>t;
		if(k>=t||k%d==0){
			cout << t<<"\n";
			return 0;
		}
		aux=((k+d-1)/d)*d;
		ll res=(2*t)/(aux+k);
		ll mod=(2*t)%(aux+k);
		if(mod<=2*k){
			cout << (res*aux)+mod/2;
			if(mod&1)cout << ".5\n";
			return 0;
		}
		cout << ((res*aux)-k+mod)<<"\n";
	}
