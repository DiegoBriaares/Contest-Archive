#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
vector<ll>v;
map<ll,bool>memo;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		memo.clear();
		v.clear();
		cin>>n;
		while(n){
			v.push_back(n%2ll);
			n/=2ll;
		}
		while(v.size()<32)v.push_back(0);
		for(int i=0;i<32;i++){
			ll p=1,s=0;
			for(int j=0;j<5;j++){
				s+=(v[(i+j)%32]*p);
				p*=2;
			}
			memo[s]=true;
		}
		bool ok=false;
		for(int i=0;i<32;i++){
			if(!memo[i]){
				cout << "no\n";
				ok=true;
				break;
			}
		}
		if(!ok)cout << "yes\n";
	}
}
