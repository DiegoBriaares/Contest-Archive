#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
#define INF 9999999999999
ll res;
ll n,k;
pair<ll,ll> v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t;
		cin>>t;
		while(t--){
			cin>>n;
			for(int i=1;i<=n;i++){
				cin>>v[i].first>>v[i].second;
			}
			ll time=1,c=0;
			for(int i=1;i<=n;i++){
				time=max(time,v[i].first);
				if(v[i].second<c||v[i].second<time)cout << "0 ";
				else {
					c++;
					cout << time<<" ";
					time++;
				}
			}
			cout << "\n";
		}
	}
