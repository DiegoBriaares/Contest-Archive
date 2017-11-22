#include <bits/stdc++.h>
using namespace std;
#define MAX 300002
int n,q,t;
int ti[MAX];
int v[MAX];
int ini[MAX];
int endd[MAX];
bool memo[MAX];
int ST[MAX*4];
int lazy[MAX*4];
vector<int>edg[MAX];
void lupd(int nodo,int a,int b){
	lazy[nodo]%=2;
	if(!lazy[nodo])return;
	ST[nodo]=(b-a)+1 - ST[nodo];
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	if(a!=b){
		lazy[left]+=lazy[nodo];
		lazy[right]+=lazy[nodo];
	}
	lazy[nodo]=0;
}
void dfs(int nodo){
	if(memo[nodo])return;
	ini[nodo]=t++;
	memo[nodo]=true;
	for(int i=0;i<edg[nodo].size();i++){
		dfs(edg[nodo][i]);
	}
	endd[nodo]=t;
}
void build(int in,int fin,int nodo){
	if(in==fin){
		ST[nodo]=ti[in];
		return;
	}
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	build(in,mid,left);
	build(mid+1,fin,right);
	ST[nodo]=ST[left]+ST[right];
}
void update(int in,int fin,int nodo,int a,int b){
	lupd(nodo,in,fin);
	if(a>fin||b<in)return;
	if(a<=in&&fin<=b){
		lazy[nodo]++;
		lupd(nodo,in,fin);
		return;
	}
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	update(in,mid,left,a,b);
	update(mid+1,fin,right,a,b);
	ST[nodo]=ST[left]+ST[right];
}
int query(int in,int fin,int nodo,int a,int b){
	lupd(nodo,in,fin);
	if(a>fin||b<in)return 0;
	if(a<=in&&fin<=b){
		return ST[nodo];
	}
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	return query(in,mid,left,a,b)+query(mid+1,fin,right,a,b);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<n;i++){
			int x;
			cin>>x;
			x--;
			edg[x].push_back(i);
		}
		t=0;
		dfs(0);
		for(int i=0;i<n;i++){
			cin>>ti[i];
			if(ti[i])update(0,n-1,0,ini[i],ini[i]);
		}
		for(int i=0;i<n;i++)endd[i]--;
		cin>>q;
		while(q--){
			string op;
			cin>>op;
			if(op[0]=='p'){
				int x;
				cin>>x;
				x--;
				update(0,n-1,0,ini[x],endd[x]);
			}
			else {
				int x;
				cin>>x;
				x--;
				cout << query(0,n-1,0,ini[x],endd[x])<<"\n";
			}
		}
	}
