#include <bits/stdc++.h>
using namespace std;
#define MAX 102
#define ll long long
int n;
map<ll,ll>memo;
pair<ll,ll>v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i].first;
			memo[v[i].first];
		}
		int p=0;
		for(map<ll,ll>::iterator it=memo.begin();it!=memo.end();++it){
			v[p].second=it->first;
			it->second=p++;
		}
		for(int i=0;i<n;i++){
			cout << v[(memo[v[i].first]+1)%n].second<<" ";
		}
		cout << "\n";
	}
