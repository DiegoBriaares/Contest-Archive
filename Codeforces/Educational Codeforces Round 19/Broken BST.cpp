#include <bits/stdc++.h>
using namespace std;
#define MAX 200002
#define ll long long
int nodes;
map<ll,bool>ok;
ll dads[MAX];
ll values[MAX];
pair<int,int>graph[MAX];
void dfs(int node,ll l,ll r){
	if(node==-1)return;
	ok[values[node]]|=(values[node]<l&&values[node]>=r);
	dfs(graph[node].first,min(l,values[node]),r);
	dfs(graph[node].second,l,max(r,values[node]));
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>nodes;
		for(int i=1;i<=nodes;i++){
			int val,a,b;
			cin>>val>>a>>b;
			values[i]=val;
			graph[i].first=a;
			graph[i].second=b;
			if(a!=-1)dads[a]=i;
			if(b!=-1)dads[b]=i;
		}
		for(int i=1;i<=nodes;i++){
			if(!dads[i]){
				dfs(i,(1<<30),-(1<<30));
				break;
			}
		}
		ll r=0;
		for(int i=1;i<=nodes;i++){
			if(!ok[values[i]])r++;
		}
		cout << r<<"\n";
	}
