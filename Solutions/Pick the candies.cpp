#include <bits/stdc++.h>
using namespace std;
#define MAX 10002
int n,k;
int a,b;
int v[MAX];
int ST[4*MAX];
void build(int in,int fin,int nodo){
	if(in==fin){
		ST[nodo]=v[in];
		return;
	}
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	build(in,mid,left);
	build(mid+1,fin,right);
	ST[nodo]=max(ST[left],ST[right]);
}
int query(int in,int fin,int nodo){
	if(a>fin||b<in)return -(1<<30);
	if(a<=in&&fin<=b){
		return ST[nodo];
	}
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	return max(query(in,mid,left),query(mid+1,fin,right));
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		memset(ST,0,sizeof(ST));
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		build(0,n-1,0);
		for(int i=0;(i+k)-1<n;i++){
			a=i,b=i+k-1;
			cout << query(0,n-1,0)<<" ";
		}
		cout << "\n";
	}
}
