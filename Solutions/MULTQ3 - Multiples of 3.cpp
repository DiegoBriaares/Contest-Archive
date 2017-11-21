#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
int n,k;
int a,b;
struct node {
	int cero;
	int uno;
	int dos;
};
node tree[MAX*4];
int lazy[MAX*4];
void suma(int nodo,int x){
	if(x==1){
		swap(tree[nodo].cero,tree[nodo].uno);
		swap(tree[nodo].uno,tree[nodo].dos);
	}
	if(x==2){
		swap(tree[nodo].cero,tree[nodo].uno);
		swap(tree[nodo].cero,tree[nodo].dos);
	}
}
void build(int in,int fin,int nodo){
	if(in==fin){
		tree[nodo].cero++;
		return;
	}
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	build(in,mid,left);
	build(mid+1,fin,right);
	tree[nodo].cero=tree[left].cero+tree[right].cero;
}
void update(int in,int fin,int nodo){
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	if(lazy[nodo]){
		lazy[nodo]%=3;
		suma(nodo,lazy[nodo]);
		if(in!=fin){
			lazy[left]+=lazy[nodo];
			lazy[right]+=lazy[nodo];
		}
		lazy[nodo]=0;
	}
	if(a>fin||b<in)return;  //No overlap
	if(a<=in&&fin<=b){  //Total Overlap
		suma(nodo,1);
		if(in!=fin){
			lazy[left]++;
			lazy[right]++;
		}
		return;
	}
	update(in,mid,left);
	update(mid+1,fin,right);
	tree[nodo].cero=tree[left].cero+tree[right].cero;
	tree[nodo].dos=tree[left].dos+tree[right].dos;
	tree[nodo].uno=tree[left].uno+tree[right].uno;
}
int query(int in,int fin,int nodo){
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	if(lazy[nodo]){
		lazy[nodo]%=3;
		suma(nodo,lazy[nodo]);
		if(in!=fin){
			lazy[left]+=lazy[nodo];
			lazy[right]+=lazy[nodo];
		}
		lazy[nodo]=0;
	}
	if(a>fin||b<in)return 0;  //No overlap
	if(a<=in&&fin<=b){  //Total Overlap
		return tree[nodo].cero;
	}
	return query(in,mid,left)+query(mid+1,fin,right);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		build(0,n-1,0);
		while(k--){
			int op;
			cin>>op>>a>>b;
			if(!op){ //updatear.
				update(0,n-1,0);
			}
			else {  //query.
				cout << query(0,n-1,0)<<"\n";
			}
		}
	}
