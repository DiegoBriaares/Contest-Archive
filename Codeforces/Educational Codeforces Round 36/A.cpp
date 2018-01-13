#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
#define INF 999999999999999999
ll n,k;
ll v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>v[i];
		}
		sort(v+1,v+n+1);
		for(int i=n;i>=1;i--){
			if(k%v[i]==0){
				cout << (k/v[i])<<"\n";
				return 0;
			}
		}
	}
