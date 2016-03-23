#include <bits/stdc++.h>
using namespace std;
#define MAX 252
int v[MAX],n,e,a,r=(1<<20);
void solve(int i,int s){
	if(i==a&&s<=e){
		r=min(r,s);
		return;
	}
	if(s>e)return;
	for(int j=0;j<n;j++){
		solve(i+v[j],s+v[j]);
		solve(i-v[j],s+v[j]);
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>e>>a;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		solve(0,0);
		if(r!=(1<<20))cout <<r<<"\n";
		else cout <<-1;
	}
