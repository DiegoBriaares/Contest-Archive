#include <bits/stdc++.h>
using namespace std;
#define MAX 52
#define ll long long
ll n,x,up,down,mid;
ll v[MAX];
ll memo[MAX][MAX][MAX][6];
ll dp(int i,int d,int w,int k){
	if(i<1&&d>n)return 0;
	if(memo[i][d][w][k]!=-1)return memo[i][d][w][k];
	ll uso=(1<<30),aux=(1<<30);
	if(w==mid){
		if(i>0){
			aux=abs(v[i]-v[mid])+dp(i-1,d,i,4);
			uso=min(uso,aux);
		}
		if(d<=n){
			aux=abs(v[d]-v[mid])+dp(i,d+1,d,4);
			uso=min(uso,aux);
		}
	}
	else {
		if(i>0&&k){
			aux=abs(v[i]-v[w])+dp(i-1,d,i,k-1);
			uso=min(uso,aux);
		}
		if(d<=n&&k){
			aux=abs(v[d]-v[w])+dp(i,d+1,d,k-1);
			uso=min(uso,aux);
		}
		aux=abs(v[mid]-v[w])+dp(i,d,mid,k);
		uso=min(uso,aux);
	}
	return memo[i][d][w][k]=uso;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		while(cin>>n){
			memset(memo,-1,sizeof(memo));
			memset(v,0,sizeof(v));
			ll res=n;
			for(int i=1;i<=n;i++){
				cin>>v[i];
			}
			cin>>x;
			bool ok=false;
			for(int i=1;i<=n;i++){
				if(v[i]==x){
					ok=true;
					break;
				}
			}
			if(ok){
				sort(v+1,v+n+1);
			}
			else {
				v[n+1]=x;
				sort(v+1,v+n+2);
				n++;
			}
			mid=1;
			while(v[mid]<x){
				mid++;
			}
			up=mid-1;
			down=mid+1;
			cout << dp(up,down,mid,5)+res<<"\n";
		}
	}
