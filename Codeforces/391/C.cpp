#include <bits/stdc++.h>
using namespace std;
#define MAX 510002
#define MAXN 1000002
#define ll long long
#define MOD 1000000007
#define INF 9999999999999
ll res;
ll n,m;
ll fact[MAXN];
vector<ll>grp;
vector<ll> poks[MAXN];
	int main (){
	//	ios_base::sync_with_stdio(0);
	//	cin.tie(0);
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=0;j<k;j++){
				int x;
				cin>>x;
				poks[x].push_back(i);
			}
		}
		fact[0]=1LL;
		for(int i=1;i<=max(n,m);i++){
			fact[i]=fact[i-1]*i;
			fact[i]%=MOD;
		}
		for(int i=1;i<=m;i++){
			sort(poks[i].begin(),poks[i].end());
		}
		sort(poks+1,poks+m+1);
		int c=0;
		for(int i=2;i<=m;i++){
				if(poks[i]==poks[i-1])c++;
				else {
					grp.push_back(c+1);
					c=0;
				}
		}
		if(c>0)grp.push_back(c+1);
		res=1LL;
		for(int i=0;i<grp.size();i++){
			res*=fact[grp[i]];
			res%=MOD;
		}
		cout << res<<"\n";
	}
