#include <bits/stdc++.h>
using namespace std;
#define MAX 300002
#define ll long long
ll n,q;
ll v[MAX];
ll ST[MAX];
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
	ST[nodo]=min(ST[left],ST[right]);
}
ll query(int a,int b,int in,int fin,int nodo){
	if(a<=in&&b>=fin) //Total Overlap
		return ST[nodo];
	if(a>fin||b<in) //No Overlap
		return (1<<30);
	//Partial Overlap
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	return min(query(a,b,in,mid,left),query(a,b,mid+1,fin,right));
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t,a,b,k;
		cin>>t;
		for(int z=1;z<=t;z++){
			memset(ST,0,sizeof(ST));
			cin>>n>>q;
			for(k=1;k<n;k*=2);
			for(int i=0;i<n;i++){
				cin>>v[i];
			}
			if(k-n>0)for(int i=n;i<k;i++)v[i]=(1<<30);
			build(0,n-1,0);
			cout << "Scenario #"<<z<<":\n";
			while(q--){
				cin>>a>>b;
				cout << query(--a,--b,0,n-1,0)<<"\n";
			}
		}
	}
