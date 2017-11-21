#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
int n,q;
int l,r,x,y;
ll v[MAX];
ll powers[10];
struct node {
	int pot[10][10];
};
struct nodeL {
	int a,b;
	bool ok;
};
void precalc(){
	for(ll i=1,j=0;j<10;j++,i*=10){
		powers[j]=i;
	}
}
node ST[4*MAX];
nodeL lazy[4*MAX];
void lazy_update(int nodo,int in,int fin){
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	for(int i=0;i<10;i++){
			ST[nodo].pot[i][lazy[nodo].b]+=ST[nodo].pot[i][lazy[nodo].a];
			ST[nodo].pot[i][lazy[nodo].a]=0;
		}
		if(in!=fin){
			lazy[left].ok=true;
			lazy[right].ok=true;
			lazy[left].a=lazy[nodo].a;
			lazy[left].b=lazy[nodo].b;
			lazy[right].a=lazy[nodo].a;
			lazy[right].b=lazy[nodo].b;
		}
		lazy[nodo].ok=false;
}
void lazy_act(int nodo,int in,int fin){
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	for(int i=0;i<10;i++){
			ST[nodo].pot[i][y]+=ST[nodo].pot[i][x];
			ST[nodo].pot[i][x]=0;
		}
		if(in!=fin){
			lazy[left].ok=true;
			lazy[right].ok=true;
			lazy[left].a=x;
			lazy[left].b=y;
			lazy[right].a=x;
			lazy[right].b=y;
		}
}
void act(int nodo){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			ST[nodo].pot[i][j]=ST[(nodo*2)+1].pot[i][j]+ST[(nodo*2)+2].pot[i][j];
		}
	}
}
void build(int in,int fin,int nodo){
	if(in==fin){
		int p=0;
		while(v[in]){
			ST[nodo].pot[p][v[in]%10]++;
			v[in]/=10;
			p++;
		}
		return;
	}
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	build(in,mid,left);
	build(mid+1,fin,right);
	act(nodo);
}
ll query(int in,int fin,int nodo){
	if(in>r||fin<l)return 0;
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	if(lazy[nodo].ok){
		lazy_update(nodo,in,fin);
	}
	if(l<=in&&fin<=r){
		ll s=0;
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				s+=(ll)((j*powers[i])*ST[nodo].pot[i][j]);
			}
		}
		return s;
	}
	return query(in,mid,left)+query(mid+1,fin,right);
}
void update(int in,int fin,int nodo){
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	if(in>r||fin<l)return;
	if(lazy[nodo].ok){
		lazy_update(nodo,in,fin);
	}
	if(l<=in&&fin<=r){
		lazy_act(nodo,in,fin);
		return;
	}
	update(in,mid,left);
	update(mid+1,fin,right);
	act(nodo);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		precalc();
		cin>>n>>q;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		build(0,n-1,0);
		while(q--){
			int op;
			cin>>op>>l>>r;
			l--,r--;
			if(op==1){   //Update
				cin>>x>>y;
				if(x!=y)update(0,n-1,0);
			}
			else {   //Query
				cout << query(0,n-1,0)<<"\n";
			}
		}
	}
