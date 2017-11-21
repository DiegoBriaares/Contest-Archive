#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
#define ll long long
int n,m,q;
ll s[MAX][MAX];
ll solve(int i,int up,int dow){
	up=max(1,up);
	dow=min(m,dow);
	return s[i][dow]-s[i][up-1];	
}
ll query(int x,int y,int d){
	int U=max(1,x-d),D=min(n,x+d);
	ll r=0;
	for(int i=U;i<=D;i++){
		int aux=d-abs(x-i);
		r+=solve(i,y-aux,y+aux);
	}	
	return r;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>s[i][j];
			s[i][j]+=s[i][j-1];
		}
	cin>>q;
	for(int i=1;i<=q;i++){
		int x,y,d;
		cin>>x>>y>>d;
		x++,y++;
		cout<<query(x,y,d)<<"\n";
	}	
}
