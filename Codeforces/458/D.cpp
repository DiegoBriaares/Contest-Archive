#include <bits/stdc++.h>
using namespace std;
#define MAX 510002
#define ll long long
ll n;
ll ok;
ll a,b,x;
ll v[MAX];
ll ST[4*MAX];
ll gcd(ll a, ll b) {
	return b?gcd(b,a%b):a;
}
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
	ST[nodo]=gcd(ST[left],ST[right]);
}
bool bad(int in,int fin){
	if(in>b||fin<a)return true;
	return false;
}
void query(int in,int fin,int nodo){
	if(in>b||fin<a||ok<=0)return;
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	if(a<=in&&fin<=b){
		if(gcd(ST[nodo],x)!=x){
			if(ok==1||in==fin){
				ok--;
			}
			else {
				query(in,mid,left);
				query(mid+1,fin,right);
			}
		}
		return;
	}
	query(in,mid,left);
	query(mid+1,fin,right);
}
void update(int in,int fin,int nodo){
	if(in>a||fin<a)return;
	if(in==fin&&in==a){
		ST[nodo]=x;
		return;
	}
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	update(in,mid,left);
	update(mid+1,fin,right);
	ST[nodo]=gcd(ST[left],ST[right]);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++)cin>>v[i];
		build(1,n,0);
		int q;
		cin>>q;
		while(q--){
			int op;
			cin>>op;
			if(op==1){
				cin>>a>>b>>x;
				ok=2;
				query(1,n,0);
				if(ok>0){
					cout << "YES\n";
				}
				else cout << "NO\n";
			}
			else {
				cin>>a>>x;
				update(1,n,0);
			}
		}
	}
