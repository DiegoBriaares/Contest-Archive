#include <bits/stdc++.h>
using namespace std;
#define ul unsigned long long
ul n,m;
ul f(ul n){
	ul k=2,r=1,i;
	while(k*k<=n){
		i=1;
		while(n%k==0){
			n/=k;
			i++;
		}
		r*=i;
		if(k==2)k++;
		else k+=2;
	}
	if(n>1)r*=2;
	return r;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>m;
		cout << f(__gcd(n,m))<<"\n";
	}
