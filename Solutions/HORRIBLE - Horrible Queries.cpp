#include <bits/stdc++.h>
using namespace std;
#define MAX 300002
#define ll long long
ll n,q,v,a,b;
ll ST[MAX];
ll lazy[MAX];
void update(ll in,ll fin,ll nodo){
	if(a>b)return;
	ll mid=(in+fin)/2;
	ll left=(nodo*2)+1;
	ll right=(nodo*2)+2;
	if(lazy[nodo]){
		ST[nodo]+=lazy[nodo]*(fin-in+1);
		if(in!=fin){
			lazy[left]+=lazy[nodo];
			lazy[right]+=lazy[nodo];
		}
		lazy[nodo]=0;
	}
	if(b<in||a>fin)return;  //No Overlap
	if(a<=in&&fin<=b){     //Total Overlap
		ST[nodo]+=(v*(fin-in+1));
		if(in!=fin){
			lazy[left]+=v;
			lazy[right]+=v;
		}
		return;
	}
	update(in,mid,left);
	update(mid+1,fin,right);
	ST[nodo]=ST[left]+ST[right];
}
ll query(ll in,ll fin,ll nodo){
	if(a>fin||b<in||a>b)return 0;  //No Overlap
	ll mid=(in+fin)/2;
	ll left=(nodo*2)+1;
	ll right=(nodo*2)+2;
	if(lazy[nodo]){
		ST[nodo]+=lazy[nodo]*(fin-in+1);
		if(in!=fin){
			lazy[left]+=lazy[nodo];
			lazy[right]+=lazy[nodo];
		}
		lazy[nodo]=0;
	}
	if(a<=in&&fin<=b){  //Total Overlap
		return ST[nodo];
	}
	//Partial Overlap
	return (query(in,mid,left)+query(mid+1,fin,right));
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		ll t;
		cin>>t;
		while(t--){
			memset(ST,0,sizeof(ST));
			memset(lazy,0,sizeof(lazy));
			cin>>n>>q;
			while(q--){
				ll op;
			cin>>op>>a>>b;
			a--;
			b--;
			if(!op){
				cin>>v;
				update(0,n-1,0);
			}
			else {
				cout << query(0,n-1,0)<<"\n";
			}
			}
		}
	}
