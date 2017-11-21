#include <bits/stdc++.h>
using namespace std;
#define MAXN 1021
#define ll long long
ll r;
ll v[MAXN];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int n,m,k,t,x;
		cin>>t;
		while(t--){
			r=0;
			cin>>n>>m>>k;
			for(int i=0;i<m;i++){
				cin>>v[i];
			}
			cin>>x;
			for(int i=0;i<m;i++){
				int aux=0;
				for(int j=0;j<n;j++){
					if((x&(1<<j))&&!(v[i]&(1<<j))||!(x&(1<<j))&&(v[i]&(1<<j)))aux++;
				}
				if(aux<=k)r++;
			}
			cout << r<<"\n";
		}
	}
