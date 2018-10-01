#include<bits/stdc++.h>
using namespace std;
#define NN pair<nodo<T> *,nodo<T> *>
#define ll long long

template <class T>
struct nodo{
    T v;
    ll key,s;
    ll sum;
    ll lazy
    nodo<T> *left,*right;
    nodo<T>(T x){
        v=x;
        left=NULL;
        right=NULL;
        s=1;
        key=rand();
        lazy = 0;
        sum = 0;
    }
};

template <class T>
class treap{
    public:
    nodo<T> *root=NULL;
    treap(){root=NULL;}
    void update(nodo<T> *P){
        if (P!=NULL) {
            
            P->s=1;
            
            P->sum = (P->left!=NULL ? P->left->sum : 0) + P->v + (P->right!=NULL ? P->right->sum : 0);
            
            if (P->left!=NULL) P->s+=P->left->s;
            if (P->right!=NULL) P->s+=P->right->s;
        }
    }
    nodo<T> *Merge(nodo<T> *P,nodo<T> *Q){
        push(P);
        push(Q);
        if (P==NULL) return Q;
        if (Q==NULL) return P;
        if (P->key > Q->key){
            P->right=Merge(P->right,Q);
            update(P);
            return P;
        }
        else {
            Q->left=Merge(P,Q->left);
            update(Q);
            return Q;
        }
    }
    void push(node<T> *P){
        if(P != NULL && P->lazy != 0){
            if(P->left != NULL)
                P->left->lazy += P->lazy;
            if(P->right != NULL)
                P->right->lazy += P->lazy;
            P->sum += P->lazy * P->s;
            P->lazy = 0;
        }
    }
    
    NN split(nodo<T> *P,int k){
        push(P);
        if (P==NULL) return NN(NULL,NULL);
        if (k==P->s) return NN(P,NULL);
        if (k==0) return NN(NULL,P);
        if (P->left!=NULL && P->left->s >= k){
            push(P->left);
            NN aux=split(P->left,k);
            P->left=NULL;
            update(P);
            P=Merge(aux.second,P);
            return NN(aux.first,P);
        }
        else {
            push(P->right);
            if (P->left!=NULL) k-=P->left->s;
            NN aux=split(P->right,k-1);
            P->right=NULL;
            update(P);
            P=Merge(P,aux.first);
            return NN(P,aux.second);
        }
    }
    ll cont(nodo<T> *P, T x){
        push(P);
        if (P==NULL) return 0;
        if (P->v >= x) return cont(P->left,x);
        if (P->left==NULL) return 1+cont(P->right,x);
        else return cont(P->right,x)+P->left->s+1;
    }
    ll posicion(T x){
        if (root==NULL) return -2;
        ll k1,k2;
        k1=cont(root,x);
        k2=root->s-cont(root,x+1);
        if (k1+k2==root->s) return -2;
        else return k1;
    }
    T busca(int k, nodo<T> *P){
        if (root==NULL) return -1;
        if (k<=0 || k > root->s) return -1;
        //if (P==NULL) P=root;
        if ((P->left!=NULL ? P->left->s : 0) +1 == k) return P->v;
        if ((P->left!=NULL ? P->left->s : 0)>=k) return busca(k,P->left);
        else return busca(k-(P->left!=NULL ? P->left->s : 0)-1, P->right);
    }
    void inser(T x){
        NN aux=split(root,cont(root,x));
        nodo<T> *P=new nodo<T>(x);
        root=Merge(Merge(aux.first,P),aux.second);
    }
    void elimina(nodo<T> *P){
        if (P==NULL) return;
        elimina(P->left);
        elimina(P->right);
        delete P;
    }
    void del(T x){
        int k=cont(root,x);
        NN aux=split(root,k);
        int kx=cont(aux.second,x+1);
        NN aux2=split(aux.second,kx);
        elimina(aux2.first);
        root=Merge(aux.first,aux2.second);
    }
    void print(nodo<T> *P=NULL, int s=0){
        if (root==NULL) return;
        if (P==NULL) P=root;
        if (P->left!=NULL)
            print(P->left, s+1
            );
        for(int i=0; i<s; i++) cout << " ";
        cout<<P->v<<'\n';
        if (P->right!=NULL) print(P->right, s+1);
    }
};


int main(){
    return 0;
}
