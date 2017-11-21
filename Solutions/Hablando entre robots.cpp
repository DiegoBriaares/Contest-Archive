#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
#define ll long long
int n,m;
map<ll,ll>h1,h2;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			ll x,y;
			cin>>x>>y;
			x++,y++;
			h1[x]=y;
			h2[y]=x;
		}	
		cin>>m;
		for(int i=0;i<m;i++){
			ll d,p;
			cin>>d>>p;
			p++;
			if(!d)cout <<h1[p]-1<<"\n";
			else cout <<h2[p]-1 <<"\n";
		}
	}
