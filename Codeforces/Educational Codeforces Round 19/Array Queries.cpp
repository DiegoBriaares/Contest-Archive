#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
int n,q;
int p,k;
int r[MAX];
int v[MAX];
pair<int,pair<int,int> > querys[MAX];
int memo[MAX],vis[MAX];
int dp(int i){
	if(i>n)return 0;
	if(vis[i]==k)return memo[i];
	vis[i]=k;
	return memo[i]=1+dp(i+k+v[i]);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i];
		}
		cin>>q;
		for(int i=0;i<q;i++){
			cin>>querys[i].second.first>>querys[i].first;
			querys[i].second.second=i;
		}
		sort(querys,querys+q);
		for(int i=0;i<q;i++){
			p=querys[i].second.first,k=querys[i].first;
			r[querys[i].second.second]=dp(p);
		}
		for(int i=0;i<q;i++){
			cout << r[i]<<"\n";
		}
	}
