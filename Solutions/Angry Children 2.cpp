#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
#define INF 99999999999999999
ll n,k;
ll v[MAX];
ll f[MAX];
ll res,sum;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		sort(v,v+n);
		for(int i=0;i<k;i++){
			if(i)f[i]=f[i-1];
			f[i]+=v[i]+v[i];
			sum+=((v[i]*i)-(v[i]*((k-1)-i)));
		}
		res=sum;
		for(int i=k;i<n;i++){
			f[i]=f[i-1]+v[i]+v[i];
			sum+=(v[i]*(k-1));
			sum+=(v[i-k]*(k-1));
			ll aux=f[i-1]-f[i-k];
			sum-=(aux);
			res=min(res,sum);
		}
		cout << res<<"\n";
	}
