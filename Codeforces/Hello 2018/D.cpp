#include <bits/stdc++.h>
using namespace std;
#define MAX 300002
#define ll unsigned long long
#define INF 999999999999999999
ll n,t;
vector<ll>res,aux;
pair<ll,pair<ll,ll> >v[MAX];
bool solve(ll k){
	aux.clear();
	ll sum=0,tim=0;
	for(int i=1;i<=n;i++){
		if(k<=v[i].second.first){
			if(tim+v[i].first<=t){
				sum++;
				aux.push_back(v[i].second.second);
				tim+=v[i].first;
			}
		}
		if(sum>=k)return true;
	}
	return false;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>t;
		for(int i=1;i<=n;i++){
			cin>>v[i].second.first>>v[i].first;
			v[i].second.second=i;
		}
		sort(v+1,v+n+1);
		int in=0,fin=n,la=0;
		while(in<=fin){
			int mid=(in+fin)/2;
			if(solve(mid)){
				res=aux;
				la=mid;
				in=mid+1;
			}
			else fin=mid-1;
		}
		cout << la<<"\n";
		cout << res.size()<<"\n";
		for(int i=0;i<res.size();i++)cout << res[i]<<" ";
		cout << "\n";
	}
