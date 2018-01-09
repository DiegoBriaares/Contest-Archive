#include <bits/stdc++.h>
using namespace std;
#define MAX 32
#define ll unsigned long long
#define INF 999999999999999999
ll n,k,res,l;
ll pot[MAX];
ll v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		pot[0]=1LL;
		for(int i=1;i<MAX;i++)pot[i]=pot[i-1]*2LL;
		v[0]=INF;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		for(int i=1;i<32;i++){
			if(2*v[i-1]<v[i]||v[i]==0)v[i]=2*v[i-1];
		}
		for(int i=0;i<32;i++){
			if(i==0){
				res+=v[i]*(k%2);
			}
			else {
				if(res>v[i])res=v[i];
				if((k&(1LL<<i)))res+=v[i];
			}
		}
		cout << res<<"\n";
	}
