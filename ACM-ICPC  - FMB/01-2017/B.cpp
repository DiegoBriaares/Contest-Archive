#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
#define ll long long
struct node {
	ll size;
	ll *arr;
};
int n,q;
int a,b,k;
ll v[MAX];
node ST[4*MAX];
void solve(ll res[],ll x[],ll y[],int n2,int n3){
	int i=0,j=0,idx=0;
	while(i<n2&&j<n3){
		if(x[i]<y[j]){
			res[idx++]=x[i++];
		}
		else {
			res[idx++]=y[j++];
		}
	}
	while(i<n2){
		res[idx++]=x[i++];
	}
	while(j<n3){
		res[idx++]=y[j++];
	}
}
void build(int in,int fin,int nodo){
	if(in==fin){
		ST[nodo].size=1;
		ST[nodo].arr = new ll[1];
		ST[nodo].arr[0]=v[in];
		return;
	}
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	build(in,mid,left);
	build(mid+1,fin,right);
	ST[nodo].size=ST[left].size+ST[right].size;
	ST[nodo].arr=new ll[ST[nodo].size];
	solve(ST[nodo].arr,ST[left].arr,ST[right].arr,ST[left].size,ST[right].size);
}
ll query(int in,int fin,int nodo){
	if(a>fin||b<in){  //No overlap
		return 0;
	}
	if(a<=in&&fin<=b){   //Total Overlap
		return ST[nodo].arr[0];
	}
	//Partial Overlap
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	return query(in,mid,left)+query(mid+1,fin,right);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		while(cin>>n>>q){
			memset(ST,0,sizeof(ST));
			for(int i=0;i<n;i++){
				cin>>v[i];
			}
			build(0,n-1,0);
			while(q--){
				cin>>a>>b>>k;
				a--,b--;
				k--;
				a+=k;
				b=a;
				cout << query(0,n-1,0)<<"\n";
			}
		}
	}
