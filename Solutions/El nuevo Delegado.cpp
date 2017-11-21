#include <bits/stdc++.h>
using namespace std;
#define MAX 400002
#define ll unsigned long long
#define MOD 1000000007
ll r;
ll n,m;
int a,b;
ll v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i];
			if(i>1)v[i]+=v[i-1];
			v[i]%=MOD;
		}
		cin>>m;
		while(m--){
			cin>>a>>b;
			r=v[b]-v[a-1];
			r+=MOD;
			r%=MOD;
			cout <<r<<"\n";
		}
	}
