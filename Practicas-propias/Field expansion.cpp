#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
int r;
ll v[MAX];
ll a,b,h,w,n;
void dfs(int i,ll x,ll y){
	if(x>=a&&y>=b){
		r=min(r,i);
		return;
	}
	if(i>n)return;
	if(v[i]==2){
		while(x<a){
			x<<=1;
			i++;
		}
		while(y<b){
			y<<=1;
			i++;
		}
		r=min(r,i);
		return;
	}
	if(x<a)dfs(i+1,x*v[i],y);
	if(y<b)dfs(i+1,x,y*v[i]);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		r=(1<<30);
		cin>>a>>b>>h>>w>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		sort(v,v+n,greater<ll>());
		dfs(0,h,w);
		dfs(0,w,h);
		if(r>n){
			cout << "-1\n";
		}
		else cout << r<<"\n";
	}
