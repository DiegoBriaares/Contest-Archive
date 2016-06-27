#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
ll n,q;
ll bit[MAX];
ll ST[1000002];
ll query(ll i){
	ll r=0;
	while(i>0){
		r+=bit[i];
		i-=(i&-i);
	}
	return r;
}
void build(int in,int fin,int nodo){
	if(in==fin){
		ST[nodo]=query(in)-query(in-1);
		return;
	}
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	build(in,mid,left);
	build(mid+1,fin,right);
	ST[nodo]=min(ST[left],ST[right]);
}
void update(ll i,ll x){
	while(i<=MAX){
		bit[i]+=x;
		i+=(i&-i);
	}
}
ll queryT(ll a,ll b,ll in,ll fin,ll nodo){
	if(a<=in&&b>=fin){ //Total Overlap
		return ST[nodo];
	}
	if(a>fin||b<in)return (1<<30);  //No Overlap
	//Partial Overlap
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	return min(queryT(a,b,in,mid,left),queryT(a,b,mid+1,fin,right));
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>q;
			update(i,q);
		}
		string v;
		ll a,b;
		cin>>q;
		while(q--){
			cin>>v>>a>>b;
			b++;
			if(v=="EAT"){
				update(b,-a);
			}
			else if(v=="GROW"){
				update(b,a);
			}
			else {
				a++;
				build(1,n,0);
				cout <<(query(b)-query(a-1))-queryT(a,b,1,n,0)<<"\n";
			}
		}
	}
