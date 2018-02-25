#include <bits/stdc++.h>
using namespace std;
#define MAX 2000009
#define ll long long
ll n,k,r;
ll v[MAX];
map<ll,bool>memo;
pair<ll,ll> arr[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i];
			if(v[i]&&!memo[v[i]])r++;
			memo[v[i]]=true;
		}
		cout << r<<"\n";
	}
