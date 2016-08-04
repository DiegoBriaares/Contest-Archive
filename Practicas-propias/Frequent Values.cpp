#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000002
#define MAX 300002
#define S 100000
int ST[MAXN];
int memo[2*MAX];
int v[MAX];
int start[2*MAX];
int n,q;
void build(int in,int fin,int nodo){
	if(in==fin){
		ST[nodo]=memo[v[in]];
		return;
	}
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	build(in,mid,left);
	build(mid+1,fin,right);
	ST[nodo]=max(ST[left],ST[right]);
}
int query(int a,int b,int in,int fin,int nodo){
	if(a<=in&&fin<=b){  //Total Overlap
		return ST[nodo];
	}
	if(a>fin||b<in){   //No Overlap
		return -(1<<30);
	}
	//Partial Overlap
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	return max(query(a,b,in,mid,left),query(a,b,mid+1,fin,right));
}
void update(int in,int fin,int nodo,int x,int i){
	if(in==fin){
		ST[nodo]=x;
		return;
	}
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	if(mid<i){
		update(mid+1,fin,right,x,i);
	}
	else update(in,mid,left,x,i);
	ST[nodo]=max(ST[left],ST[right]);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>q;
		for(int i=0;i<n;i++){
			cin>>v[i];
			v[i]+=S;
			memo[v[i]]++;
			if(memo[v[i]]==1)start[v[i]]=i;
		}
		build(0,n-1,0);
		for(int i=0;i<q;i++){
			int a,b;
			cin>>a>>b;
			a--;
			b--;
			if(v[a]==v[b])cout << (b-a)+1<<"\n";
			else {
				int k=(start[v[a]]+memo[v[a]])-1;
				int in=(k-a)+1,fin=(b-start[v[b]])+1;
				cout << max(max(in,fin),query(k+1,start[v[b]]-1,0,n-1,0))<<"\n";
			}
		}
	}
