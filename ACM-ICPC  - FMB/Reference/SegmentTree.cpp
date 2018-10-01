#include <bits/stdc++.h>
using namespace std;

template <class T>
struct nodo{
	T x;
	int i,j;
	nodo *p,*l,*r;
};

template <class T>
class ST{
	nodo<T> *root;
	public:
	void inicia(nodo<T> *P){
		if (P->i==P->j) return;
		int c=(P->i+P->j)/2;
		P->l=new nodo<T>;
		P->r=new nodo<T>;
		P->l->p=P;
		P->l->i=P->i;
		P->l->j=c;
		P->r->p=P;
		P->r->i=c+1;
		P->r->j=P->j;
		inicia(P->l);
		inicia(P->r);
	}
	ST(int n){
		root=new nodo<T>;
		root->i=0;
		root->j=n-1;
		inicia(root);
	}
	T compara(T x, T y){
		T z;//especificar comparacion
		return z;
	}
	void update(int i, T x, nodo<T> *P=NULL){
		if (P==NULL) P=root;
		if (P->i==P->j) {
			P->x=x;
			return;
		}
		int c=(P->i+P->j)/2;
		if (i<=c) update(i,x,P->l);
		else update(i,x,P->r);
		P->x=compara(P->l->x,P->r->x);
	}
	T query(int i, int j, nodo<T> *P=NULL){
		if (P==NULL) P=root;
		if (i<=P->i&&P->j<=j) return P->x;
		int c=(P->i+P->j)/2;
		if (j<=c) return query(i,j,P->l);
		else if (i>c) return query(i,j,P->r);
		else return compara(query(i,j,P->l),query(i,j,P->r));
	}
	void del(nodo<T> *P=NULL){
		if (P==NULL) P=root;
		if (P->i==P->j) delete P;
		else {
			del(P->l);
			del(P->r);
			delete P;
		}
	}
};

int main(){
	return 0;
}
