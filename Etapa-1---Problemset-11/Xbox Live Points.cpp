#include <bits/stdc++.h>
using namespace std;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		long long i,j,k,n,r;
		cin>>n;
		long long v[n];
		for(i=0;i<n;i++){
			cin>>v[i];
		}
		k=v[n-1];
		r=k;
		for(i=n-2;i>=0;i--){
			k=max(v[i],k+v[i]);
			if(k>r)r=k;
		}
		cout << r << "\n";
	}
