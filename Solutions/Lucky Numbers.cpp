#include <bits/stdc++.h>
using namespace std;
#define MAX 200002
#define ll long long
vector<int> v;
bool eratos[MAX];
ll memo[21][201][2001];
void conv(ll x){
	while(x>0){
		v.push_back(x%10);
		x/=10LL;
	}
}
void criba(){
	for(int i=2;i<MAX;i++){
		if(!eratos[i]){
			for(int j=i+i;j<MAX;j+=i)eratos[j]=true;
		}
	}
}
ll dp(int pos,int s,int s2,bool ok){
	if(pos==-1){
		if(!eratos[s2]&&!eratos[s]){
			return 1;
		}
		return 0;
	}
	if(!ok&&memo[pos][s][s2]!=-1)return memo[pos][s][s2];
	int lim=(ok?v[pos]:9);
	ll ans=0;
	for(int i=0;i<=lim;i++){
		ans+=dp(pos-1,s+i,s2+i*i,ok&&i==lim);
	}
	if(ok)return ans;
	return memo[pos][s][s2]=ans;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		criba();
		eratos[0]=eratos[1]=true;
		int t;
		memset(memo,-1,sizeof(memo));
		cin>>t;
		while(t--){
			ll a,b;
			cin>>a>>b;
			v.clear();
			conv(b);
			ll res=dp(v.size()-1,0,0,1);
			v.clear();
			conv(a-1);
			ll res2;
			if(a<=1)res2=0;
			else res2=dp(v.size()-1,0,0,1);
			cout << res-res2<<"\n";
		}
	}
