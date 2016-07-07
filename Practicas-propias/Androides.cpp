#include <bits/stdc++.h>
using namespace std;
#define MAX 500002
int n,q,uso;
int ST[MAX];
int lazy[MAX];
void update(int a,int b,int in,int fin,int nodo){
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	if(a>fin||b<in)return; //No Overlap
	if(in==fin){
		ST[nodo]=!ST[nodo];
		return;
	}
	if(a<=in&&fin<=b){  //Total Overlap
		lazy[nodo]=!lazy[nodo];
		uso=((fin-in+1)-ST[nodo]);
		ST[nodo]=uso;
		return;
	}
	//Partial Overlap
	update(a,b,in,mid,left);
	update(a,b,mid+1,fin,right);
	ST[nodo]=ST[left]+ST[right];
	if(lazy[nodo]){
		uso=((fin-in+1)-ST[nodo]);
		ST[nodo]=uso;
	}
}
int query(int a,int b,int in,int fin,int nodo,int uso){
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	if(a>fin||b<in)return 0; //No Overlap
	if(a<=in&&fin<=b){  //Total Overlap
		if(uso%2==0)return ST[nodo];
		else {
			uso=((fin-in+1)-ST[nodo]);
			return uso;
		}
	}
	//Partial Overlap
	uso+=lazy[nodo];
	int q1=query(a,b,in,mid,left,uso);
	int q2=query(a,b,mid+1,fin,right,uso);
	return q1+q2;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>q;
		for(int i=0;i<q;i++){
			int op,a,b;
			cin>>op>>a>>b;
			a--;
			b--;
			if(!op){
				update(a,b,0,n-1,0);
			}
			else {
				cout << query(a,b,0,n-1,0,0)<<"\n";
			}
		}
	}
