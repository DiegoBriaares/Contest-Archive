#include <bits/stdc++.h>
using namespace std;
#define MAXN 300002
int der[MAXN],izq[MAXN],clave[MAXN],nodos=0,c=0;
int crear_nodo(int n){
	clave[nodos]=n;
	der[nodos]=-1;
	izq[nodos]=-1;
	return nodos++;
}
void meter(int nodo,int n){
	c++;
	if(n<clave[nodo]){
		if(izq[nodo]==-1){
			izq[nodo]=crear_nodo(n);
		}
		else {
			meter(izq[nodo],n);
		}
	}
	else {
		if(der[nodo]==-1){
			der[nodo]=crear_nodo(n);
		}
		else {
			meter(der[nodo],n);
		}
	}
}
	int main (){
		int n,i,raiz;
		cin>>n;
		int v[n];
		for(i=0;i<n;i++){
			cin>>v[i];
		}
		for(i=0;i<n;i++){
			if(i==0){
				raiz=crear_nodo(v[i]);
			}
			else {
				meter(raiz,v[i]);
			}
			cout <<c<<"\n";
		}
	}
