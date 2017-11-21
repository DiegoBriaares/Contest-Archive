#include <bits/stdc++.h>
using namespace std;
#define MAX 300002
#define ll long long
#define par pair<ll,ll>
ll n,q;
ll v[MAX];
ll memo[MAX];
par ST[MAX];
par maxi(par a,par b){
	ll uso[5];
	uso[0]=a.first;
	uso[1]=a.second;
	uso[2]=b.first;
	uso[3]=b.second;
	sort(uso,uso+4);
	return make_pair(uso[2],uso[3]);
}
void build(int in,int fin,int nodo){
	if(in==fin){
		ST[nodo].first=v[in];
		ST[nodo].second=0;
		memo[in]=nodo;
		return;
	}
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	build(in,mid,left);
	build(mid+1,fin,right);
	ST[nodo]=maxi(ST[left],ST[right]);
}
par query(int a,int b,int in,int fin,int nodo){
	if(a<=in&&fin<=b){   //Total Overlap
		return ST[nodo];
	}
	if(fin<a||in>b){   //No Overlap
		return make_pair(0,0);
	}
	//Partial Overlap
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	return maxi(query(a,b,in,mid,left),query(a,b,mid+1,fin,right));
}
void update(int i,int x){
    int nodo=memo[i];
    ST[nodo]=make_pair(x,0);
    while(nodo>0){
    	nodo=(nodo-1)/2;
        ST[nodo]=maxi(ST[(nodo*2)+1],ST[(nodo*2)+2]);
    }
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		cin>>q;
		ll a,b;
		char mander;
		build(0,n-1,0);
		while(q--){
			cin>>mander>>a>>b;
			a--;
			if(mander=='Q'){
				b--;
				par uso=query(a,b,0,n-1,0);
				cout << uso.first+uso.second<<"\n";
			}
			else {
				update(a,b);
			}
		}
	}
