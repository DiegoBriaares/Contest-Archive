#include <bits/stdc++.h>
using namespace std;
#define MAX 1000102
#define ll long long
#define MOD 1000000007
ll n,mini;
ll v[MAX],res;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i];
			if(i==1)mini=v[i];
			else mini=min(mini,v[i]);
		}
		res=(1<<30);
		ll p=-1;
		for(int i=1;i<=n;i++){
			if(v[i]==mini){
				if(p==-1){
					p=i;
				}
				else {
					res=min(res,(i-p));
					p=i;
				}
			}
		}
		cout << res<<"\n";
	}
