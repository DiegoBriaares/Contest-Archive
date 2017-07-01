#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
int n,q;
int a,b;
string v;
struct node {
	int m;
	int l;
	int r;
};
node ST[4*MAX];
void build(int in,int fin,int nodo){
	if(in==fin){
		if(v[in]=='('){
			ST[nodo].l++;
		}
		else {
			ST[nodo].r++;
		}
		return;
	}
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	build(in,mid,left);
	build(mid+1,fin,right);
	int t=min(ST[left].l,ST[right].r);
	ST[nodo].m=ST[left].m+ST[right].m+2*t;
	ST[nodo].l=ST[left].l+ST[right].l-t;
	ST[nodo].r=ST[left].r+ST[right].r-t;
}
node query(int in,int fin,int nodo){
	if(a>fin||b<in){
		node aux;
		aux.m=aux.l=aux.r=0;
		return aux;
	}
	if(a<=in&&fin<=b)return ST[nodo];
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	node l=query(in,mid,left),r=query(mid+1,fin,right);
	node res;
	int t=min(l.l,r.r);
	res.m=l.m+r.m+2*t;
	res.l=l.l+r.l-t;
	res.r=l.r+r.r-t;
	return res;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>v;
		n=v.size();
		build(0,n-1,0);
		cin>>q;
		while(q--){
			cin>>a>>b;
			a--,b--;
			cout << query(0,n-1,0).m<<"\n";
		}
	}
