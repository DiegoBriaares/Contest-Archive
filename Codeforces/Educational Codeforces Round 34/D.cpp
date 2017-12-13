#include <bits/stdc++.h>
using namespace std;
#define MAX 400002
#define MOD 1000000007
#define ll long long
long double r;
ll n;
ll bit[MAX];
ll bit2[MAX];
map<ll,ll>memo;
ll v[MAX],v2[MAX];
void update(int i,ll x){
	while(i<MAX){
		bit[i]+=x;
		i+=(i&-i);
	}
}
ll query(int i){
	if(i<=0)return 0;
	ll s=0;
	while(i>0){
		s+=bit[i];
		i-=(i&-i);
	}
	return s;
}
void update2(int i,ll x){
	while(i<MAX){
		bit2[i]+=x;
		i+=(i&-i);
	}
}
ll query2(int i){
	if(i<=0)return 0;
	ll s=0;
	while(i>0){
		s+=bit2[i];
		i-=(i&-i);
	}
	return s;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i];
			v2[i-1]=v[i];
		}
		sort(v2,v2+n);
		int c=1;
		for(int i=0;i<n;i++){
			if(i&&v2[i]-v2[i-1]>=2)c++;
			if(!memo[v2[i]])memo[v2[i]]=c++;
		}
		for(int i=1;i<=n;i++){
			r+=((query(memo[v[i]]-2))+(query2(memo[v[i]]-2)*v[i]));
			r+=(((query(MAX-1)-query(memo[v[i]]+1)))+((query2(MAX-1)-query2(memo[v[i]]+1))*v[i]));
		//	cout << "AUX: "<<r<<" "<<memo[v[i]]<<"\n";
			update(memo[v[i]],-v[i]);
			update2(memo[v[i]],1);
		}
		cout <<fixed<<setprecision(0)<< r<<"\n";
	}
