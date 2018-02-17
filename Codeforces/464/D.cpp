#include <bits/stdc++.h>
using namespace std;
#define MAX 301002
#define ll long long
#define MOD 1000000007
ll n,k;
ll v[MAX];
string a,b;
bool vis[102];
vector<int>edg[MAX];
vector<pair<char,char> >res;
map<pair<int,int>,bool>memo;
void dfs(int nodo){
	if(vis[nodo])return;
	vis[nodo]=true;
	for(int i=0;i<edg[nodo].size();i++){
		if(!memo[make_pair(nodo,edg[nodo][i])]&&!memo[make_pair(edg[nodo][i],nodo)]&&!vis[edg[nodo][i]]){
				char x=(char)(nodo+'a'),y=(char)(edg[nodo][i]+'a');
				res.push_back(make_pair(x,y));
				memo[make_pair(edg[nodo][i],nodo)]=memo[make_pair(nodo,edg[nodo][i])]=true;
			}
			dfs(edg[nodo][i]);
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		cin>>a>>b;
		for(int i=0;i<n;i++){
			edg[a[i]-'a'].push_back(b[i]-'a');
			edg[b[i]-'a'].push_back(a[i]-'a');
		}
		for(int i=0;i<26;i++){
			if(!vis[i]){
				dfs(i);
			}
		}
		cout << res.size()<<"\n";
		for(int i=0;i<res.size();i++){
			cout << res[i].first<<" "<<res[i].second<<"\n";
		}
	}
