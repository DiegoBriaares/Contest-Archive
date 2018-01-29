#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
#define INF 99999999999999999
ll c;
ll n,k,s;
ll v[MAX];
vector<ll>vec;
bool memo[MAX];
void dfs(int nodo){
	if(memo[nodo])return;
	memo[nodo]=true;
	c++;
	dfs(v[nodo]);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i];
		}
		for(int i=1;i<=n;i++){
			if(!memo[i]){
				c=0;
				dfs(i);
				vec.push_back(c);
			}
		}
		sort(vec.begin(),vec.end());
		reverse(vec.begin(),vec.end());
		for(int i=0;i<min((ll)vec.size(),2LL);i++){
			k+=vec[i];
		}
		s+=(k*k);
		for(int i=2;i<vec.size();i++){
			s+=(vec[i]*vec[i]);
		}
		cout << s<<"\n";
	}
