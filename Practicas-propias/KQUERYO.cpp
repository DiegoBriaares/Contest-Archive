#include <bits/stdc++.h>
using namespace std;
#define MAX 30002
#define ll long long
ll la;
int n,q;
ll a,b,c;
ll v[MAX];
struct node {
	ll *arr;
	ll t;
};
node ST[4*MAX];
void merge(ll mer[],ll x[],ll y[],int n1,int n2){
	int i=0,j=0,idx=0;
	while(i<n1&&j<n2){
		if(x[i]<y[j]){
			mer[idx++]=x[i++];
		}
		else {
			mer[idx++]=y[j++];
		}
	}
	while(i<n1)mer[idx++]=x[i++];
	while(j<n2)mer[idx++]=y[j++];
}
void build(int in,int fin,int nodo){
	if(in==fin){
		ST[nodo].arr=new ll[1];
		ST[nodo].arr[0]=v[in];
		ST[nodo].t=1;
		return;
	}
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	build(in,mid,left);
	build(mid+1,fin,right);
	ST[nodo].arr=new ll[ST[left].t+ST[right].t];
	ST[nodo].t=ST[left].t+ST[right].t;
	merge(ST[nodo].arr,ST[left].arr,ST[right].arr,ST[left].t,ST[right].t);
}
ll query(int in,int fin,int nodo){
	if(a>fin||b<in){   //No Overlap
		return 0;
	}
	if(a<=in&&fin<=b){   //Total Overlap
		ll *idx=upper_bound(ST[nodo].arr,ST[nodo].arr+ST[nodo].t,c);
		return ST[nodo].arr+ST[nodo].t-idx;
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
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		build(0,n-1,0);
		cin>>q;
		while(q--){
			cin>>a>>b>>c;
			a^=la;
			b^=la;
			c^=la;
			a--,b--;
			la=query(0,n-1,0);
			cout << la<<"\n";
		}
	}
