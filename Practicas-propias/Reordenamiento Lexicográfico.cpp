#include <bits/stdc++.h>
using namespace std;
#define MAX 90100
#define P 257
#define MOD 1000000007
#define ll long long
char v[MAX];
int n;
string r;
ll hashes[MAX];
ll pots[MAX];
int x,y;
int bs(int in,int fin){
	int mid;
	mid=(in+fin)/2;
	while(in<=fin){
		if((hashes[x+mid]-(x==0?0:(hashes[x-1]*pots[((x+mid)-x+1)])%MOD)%MOD)==(hashes[y]-(hashes[(y-mid)-1]*pots[((x+mid)-x+1)])%MOD)%MOD)in=mid+1;
		else fin=mid-1;
		mid=(in+fin)/2;
	}
	return fin;
}
void pw(){
	ll pot=1;
	pots[0]=1;
	for(int i=1;i<=n;i++){
			pot*=P;
			pot%=MOD;
			pots[i]=pot;
		}
}
void hashing(){
	ll r=0;
	for(int i=0;i<n;i++){
		r*=P;
		r+=(ll)(v[i]);
		r%=MOD;
		hashes[i]=r;
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		ll i,j,in=0,fin=n-1,k,k2;
		pw();
		for(i=0;i<n;i++)cin>>v[i];
		hashing();
		while(in<=fin){
			if(v[in]<v[fin])r.push_back(v[in++]);
			else if(v[in]>v[fin])r.push_back(v[fin--]);
			else {
				x=in;
				y=fin;
				int pos=bs(1,((fin-in)/2)-1);
				k=pos-in+1;
				if(v[in+k]<v[fin-k])r.push_back(v[in++]);
				else r.push_back(v[fin--]);
			}
		}
		for(i=0,j=0;i<n;i++,j++){
			if(j==80){
                cout<<"\n";
                j=0;
			}
			cout <<r[i];
		}
	}
