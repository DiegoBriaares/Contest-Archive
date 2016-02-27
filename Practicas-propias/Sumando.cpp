#include <bits/stdc++.h>
using namespace std;
#define MAX 10000002
long long v[MAX],n,r=0,k;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++)cin>>v[i];
		k=v[n-1];
		for(int i=n-2;i>=0;i--){
			k=max(k+v[i],v[i]);
			if(k>r)r=k;
		}
		cout <<r<<"\n";
	} 
