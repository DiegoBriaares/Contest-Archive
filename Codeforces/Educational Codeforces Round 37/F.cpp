#include <bits/stdc++.h>
using namespace std;
#define MAX 301002
#define MAXN 1000102
#define ll long long
ll n,q;
ll a,b;
ll v[MAX];
struct node {
	ll max;
	ll sum;
};
node ST[4*MAX];
bool comp[MAXN];
vector<ll>primos;
void criba(){
	comp[0]=comp[1]=true;
	for(int i=2;i<MAXN;i++){
		if(!comp[i]){
			for(int j=i+i;j<MAX;j+=i){
				comp[j]=true;
			}
		}
	}
}
void get_primes(){
	for(int i=2;i<MAXN;i++){
		if(!comp[i])primos.push_back(i);
	}
}
ll divi(ll k){
	ll r=1,raiz=sqrt(k);
	for(int i=0;i<primos.size();i++){
		if(k%primos[i]==0){
			int c=1;
			while(k%primos[i]==0){
				k/=primos[i];
				c++;
			}
			r*=c;
		}
		if(k==1||primos[i]>raiz)break;
	}
	if(k>1)r*=2LL;
	return r;
}
void build(int in,int fin,int nodo){
	if(in==fin){
		ST[nodo].max=v[in];
		ST[nodo].sum=v[in];
		return;
	}
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	build(in,mid,left);
	build(mid+1,fin,right);
	ST[nodo].max=max(ST[left].max,ST[right].max);
	ST[nodo].sum=(ST[left].sum+ST[right].sum);
}
ll query(int in,int fin,int nodo){
	if(in>b||fin<a)return 0;
	if(a<=in&&fin<=b)return ST[nodo].sum;
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	return query(in,mid,left)+query(mid+1,fin,right);
}
void update(int in,int fin,int nodo){
	if(in>b||fin<a||ST[nodo].max<=2)return;
	if(in==fin){
		ST[nodo].max=divi(ST[nodo].max);
		ST[nodo].sum=divi(ST[nodo].sum);
		return;
	}
	int mid=(in+fin)/2;
	int left=(nodo*2)+1;
	int right=(nodo*2)+2;
	update(in,mid,left);
	update(mid+1,fin,right);
	ST[nodo].max=max(ST[left].max,ST[right].max);
	ST[nodo].sum=(ST[left].sum+ST[right].sum);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>q;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		criba();
		get_primes();
		build(0,n-1,0);
		while(q--){
			int op;
			cin>>op>>a>>b;
			a--,b--;
			if(op==1){  //Update
				update(0,n-1,0);
			}
			else {
				cout << query(0,n-1,0)<<"\n";
			}
		}
	}
