#include <bits/stdc++.h>
using namespace std;
const int MAXN = (1<<21);
const int MAX=(1<<22)+5;
int n,q;
int op,a,b,h;
int U[MAX],D[MAX];
void act(int nodo,int d,int u){
    D[nodo] = min(D[nodo],d);
    D[nodo] = max(D[nodo], u);
    U[nodo] = max(U[nodo], u);
    U[nodo] = min(U[nodo], d);
}
void update(int in,int fin,int nodo){
	if(a>fin||b<in)return; //No Overlap
	if(a<=in&&fin<=b){   //Total Overlap
		if(op==1){  //Añadir
			U[nodo]=max(U[nodo],h);
			D[nodo]=max(D[nodo],h);
		}
		else {  //Eliminar
			U[nodo]=min(U[nodo],h);
			D[nodo]=min(D[nodo],h);
		}
		return;
	}
	//Partial Overlap
	int mid=(in+fin)/2;
	int left=(nodo*2);
	int right=(nodo*2)+1;
	act(left,D[nodo],U[nodo]);
    act(right,D[nodo],U[nodo]);   //Estas 3 operaciones son las correspondientes al lazy.
    D[nodo]=MAX, U[nodo]=0;
    update(in,mid,left);
    update(mid+1,fin,right);
}
int query(int in,int fin,int nodo){
	if(a>fin||b<in)return (1<<30); //No Overlap
	if(a<=in&&fin<=b){   //Total Overlap
		return max(D[nodo],U[nodo]);
	}
	//Partial Overlap
	int mid=(in+fin)/2;
	int left=(nodo*2);
	int right=(nodo*2)+1;
    return min(query(in,mid,left),query(mid+1,fin,right));
}
void perfect(){
	for(int nodo=1;nodo<MAXN;nodo++){
		int left=(nodo*2);
		int right=(nodo*2)+1;
		act(left,D[nodo],U[nodo]);
		act(right,D[nodo],U[nodo]);
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>q;
		while(q--){
			cin>>op>>a>>b>>h;
			a++;
			b++;
			update(1,MAXN,1);
		}
		perfect();
		for(int i=MAXN;i<(MAXN)+n;i++){
			cout <<min(D[i],U[i])<<"\n";
		}
	}
