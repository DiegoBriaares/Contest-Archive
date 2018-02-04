#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
#define INF 9999999999999
ll res;
ll n,k;
ll v[MAX];
bool h[MAX];
bool on[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t;
		cin>>t;
		while(t--){
			memset(on,false,sizeof(on));
			memset(h,false,sizeof(h));
			cin>>n>>k;
			for(int i=1;i<=k;i++){
				cin>>v[i];
				h[v[i]]=true;
			}
			int time=0;
			while(1){
				bool ok=false;
				for(int i=1;i<=n;i++){
					if(!h[i]){
						ok=true;
						break;
					}
				}
				if(!ok){
					break;
				}
				for(int i=1;i<=n;i++){
					if(!h[i]&&h[i+1]||!h[i]&&h[i-1])on[i]=true;
				}
				for(int i=1;i<=n;i++){
					if(on[i])h[i]=true;
				}
				time++;
			}
			cout << time+1<<"\n";
		}
	}
