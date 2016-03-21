#include <bits/stdc++.h>
using namespace std;
long long mc(long long a,long long b){
	long long r=(a*b)/__gcd(a,b);
	return r;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		long long n,c=0,s,r,i,j,k,h,uso,uso2=1;
		cin>>n;
		long long v[n],mcd[n],mcm[n];
		for(i=0;i<n;i++){
			cin>>v[i];
		}
		sort(v,v+n);
		k=mc(v[n-2],v[n-1]);
		cout << k << "";
	}
