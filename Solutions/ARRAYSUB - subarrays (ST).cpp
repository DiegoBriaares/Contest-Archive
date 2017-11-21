#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
int n,k;
int v[MAX];
int ST[MAX];
void build(int in,int fin,int nodo){
	if(in==fin){
		ST[nodo]=v[in];
		return;
	}
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	build(in,mid,left);
	build(mid+1,fin,right);
	ST[nodo]=max(ST[left],ST[right]);
}
int query(int a,int b,int in,int fin,int nodo){
	if(in>=a&&fin<=b){  // Total Overlap
		return ST[nodo];
	}
	if(a>fin||b<in){    //No Overlap
		return -(1<<30);
	}
	//Partial Overlap
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	return max(query(a,b,in,mid,left),query(a,b,mid+1,fin,right));
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		int in=0,fin;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		cin>>k;
		build(0,n-1,0);
		for(int i=0;i<n;i++){
			if(i==k-1){
				fin=i;
				cout << query(in,fin,0,n-1,0)<<" ";
			}
			else if(i>=k){
				in++;
				fin++;
				cout << query(in,fin,0,n-1,0)<<" ";
			}
		}
	}
