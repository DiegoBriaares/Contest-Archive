#include <bits/stdc++.h>
using namespace std;
bool prime(int k){
 int i=sqrt(k);
	while(i>1){
		if(k%i==0&&i!=sqrt(k))return false;
		i--;
	}
	return true;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int r=0,c=0,n;
		cin>>n;
		int i=sqrt(n);
		if(i*i==n)c++;
		if(!prime(n))r++;
		if(c&&!r)cout <<"cuadrado";
		else if(c&&r)cout <<"ambos";
		else if(r&&!c)cout <<"rectangulo";
		else cout <<"ninguno";
	}
