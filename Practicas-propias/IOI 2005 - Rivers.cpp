#include <bits/stdc++.h>
using namespace std;
#define MAX 102
#define ll long long
ll s;
int n;
ll bro[MAX];
ll hijo[MAX];
ll dist[MAX];
ll tree[MAX];
ll cost[MAX][MAX];
vector<pair<ll,ll> >edg[MAX];
ll memo[MAX][MAX][52];
void dfs(ll nodo,ll sum){
	dist[nodo]=sum;
	if(!edg[nodo].size())return;
	ll idx=edg[nodo][0].first;
	hijo[nodo]=idx;
	for(int i=0;i<edg[nodo].size();i++){
		if(i){
			bro[idx]=edg[nodo][i].first;
			idx=edg[nodo][i].first;
		}
		dfs(edg[nodo][i].first,sum+edg[nodo][i].second);
		tree[nodo]+=tree[edg[nodo][i].first];
		s+=(tree[edg[nodo][i].first]*edg[nodo][i].second);
	}
}
ll dp(int i,int j,int k){
	if(k==0||i==0)return 0;
	if(k<0)return -(1<<30);
	if(memo[i][j][k])return memo[i][j][k];
	ll aux=0,aux2=0;
	for(int x=0;x<k;x++){   //Tomar.
		aux2=max(aux2,dp(hijo[i],i,x)+dp(bro[i],j,(k-x-1)));
	}
	aux2+=cost[i][j];
	for(int x=0;x<=k;x++){   //No tomar.
		aux=max(aux,dp(hijo[i],j,x)+dp(bro[i],j,(k-x)));
	}
	return memo[i][j][k]=max(aux,aux2);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int b,p;
			cin>>tree[i]>>b>>p;
			edg[b].push_back(make_pair(i,p));		
		}
		dfs(0,0);
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				cost[i][j]=(tree[i]*(dist[i]-dist[j]));
			}
		}
		cout << (s-dp(hijo[0],0,k))<<"\n";
	}
