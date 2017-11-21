#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
int tree[MAX],der[MAX],izq[MAX],nodos=0,uso=0,v[MAX];
int new_nodo(int n){
	tree[nodos]=n;
	der[nodos]=-1;
	izq[nodos]=-1;
	return nodos++;
}
void in(int r,int n){
	if(n<tree[r]){
		if(izq[r]==-1)izq[r]=new_nodo(n);
		else in(izq[r],n);
	}
	else {
		if(der[r]==-1)der[r]=new_nodo(n);
		else in(der[r],n);
	}
}
void preorden(int nodo){
	if(nodo==-1)return;
	v[uso++]=tree[nodo];
	preorden(izq[nodo]);
	preorden(der[nodo]);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int n,m,i,j,k;
		cin>>n;
		for(i=0;i<n;i++){
			cin>>j;
			if(i==0)k=new_nodo(j);
			else in(k,j);
		}
		preorden(k);
		cin>>n;
		for(i=0;i<n;i++){
			cin>>j;
			cout<<v[--j]<<"\n";
		}
	}
