#include <bits/stdc++.h>
using namespace std;
#define MAX 400002
#define ll long long
ll n;
ll res,cant;
string v;
ll preff[MAX];
ll ST[8*MAX];
int cost(char x){
	x=toupper(x);
	if(x=='A'||x=='E'||x=='I'||x=='O'||x=='U')return -1;
	return 2;
}
void build(int in,int fin,int nodo){
	if(in==fin){
		ST[nodo]=preff[in];
		return;
	}
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	build(in,mid,left);
	build(mid+1,fin,right);
	ST[nodo]=min(ST[left],ST[right]);
}
int query(int in,int fin,int nodo,int a,int b,int x){
	if(in==fin)return in;
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	if(x-ST[left]>=0&&!(in>b||mid<a))return query(in,mid,left,a,b,x);
	if(x-ST[right]>=0&&!(in>mid+1||fin<a))return query(mid+1,fin,right,a,b,x);
	return -1;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>v;
		n=v.size();
		for(int i=1;i<=n;i++){
			preff[i]=preff[i-1];
			preff[i]+=cost(v[i-1]);
		}
		build(1,n,0);
		res=-(1<<30);
		for(int i=1;i<=n;i++){
			int aux=query(1,n,0,1,i-1,preff[i]);
			if(aux==-1)continue;
			if(preff[i]>=0)aux=0;
			if((i-aux)==res)cant++;
			else if((i-aux)>res){
				res=(i-aux);
				cant=1;
			}
		}
		if(!cant||!res)cout << "Sin solucion\n";
		else cout << res<< " "<<cant<<"\n";
	}
