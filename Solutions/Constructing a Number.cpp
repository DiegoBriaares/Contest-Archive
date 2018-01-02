#include <bits/stdc++.h>
using namespace std;
#define MAX 2002
#define ll long long
ll x,n;
void canConstruct(vector<ll>v){
	ll s=0;
	for(int i=0;i<v.size();i++){
		ll r=0;
		ll a=v[i];
		while(a!=0){
			r+=(a%10);
			a/=10;
		}
		s+=r;
	}
	if(s%3==0)cout << "Yes\n";
	else cout << "No\n";
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t;
		cin>>t;
		while(t--){
			cin>>n;
			vector<ll>v;
			for(int i=0;i<n;i++){
				cin>>x;
				v.push_back(x);
			}
			canConstruct(v);
		}
		
	}
