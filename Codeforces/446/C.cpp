#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
int n,k;
ll v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		ll mcd=0;
		for(int i=0;i<n;i++){
			cin>>v[i];
			if(v[i]==1)k++;
		}
		if(k){
			cout << (n-k)<<"\n";
			return 0;
		}
		for(int i=0;i<n;i++){
			mcd=__gcd(mcd,v[i]);
		}
		if(mcd>1){
			cout <<"-1\n";
			return 0;
		}
		k=(1<<30);
		for(int i=0;i<n;i++){
			ll x=v[i];
			for(int j=i+1;j<n;j++){
				x=__gcd(x,v[j]);
				if(x==1){
					k=min(k,j-i);
					break;
				}
			}
		}
		cout <<n+k-1<<"\n";
	}
