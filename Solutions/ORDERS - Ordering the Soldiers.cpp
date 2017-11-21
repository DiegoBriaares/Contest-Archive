#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
int n;
int v[MAX];
int ST[MAX];
int r[MAX];
int s[MAX];
void build(int in,int fin,int nodo){
	if(in==fin){
		ST[nodo]=1;
		return;
	}
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	build(in,mid,left);
	build(mid+1,fin,right);
	ST[nodo]=ST[left]+ST[right];
}
int query(int in,int fin,int nodo,int x){
	if(in==fin)return in;
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	if(ST[left]>=x){
		return query(in,mid,left,x);
	}
	return query(mid+1,fin,right,x-ST[left]);
}
void remove(int in,int fin,int nodo,int x){
	if(in==fin){
		ST[nodo]=0;
		return;
	}
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	if(x<=mid){
		remove(in,mid,left,x);
	}
	else remove(mid+1,fin,right,x);
	ST[nodo]=ST[left]+ST[right];
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t;
		cin>>t;
		while(t--){
			memset(ST,0,sizeof(ST));
			for(int i=0;i<MAX;i++)s[i]=i+1;
			cin>>n;
			for(int i=0;i<n;i++){
				cin>>v[i];
			}
			build(0,n-1,0);
			for(int i=n-1;i>=0;i--){
				int idx=query(0,n-1,0,(i+1)-v[i]);
				r[i]=idx;
				remove(0,n-1,0,idx);
			}
			for(int i=0;i<n;i++){
				cout << s[r[i]]<<" ";
			}
			cout <<"\n";
		}
	}
