#include <bits/stdc++.h>
using namespace std;
#define MAX 20
#define T 280
#define min first
#define pb(a,b,c,d) make_pair(a,make_pair(b,make_pair(c,d)))
#define par pair<int,pair<int,pair<int,int> > >
int n;
int res;
int m[5][MAX];
bool memo[5][(1<<16)];
void solve(){
	priority_queue<par >pq;
	pq.push(pb(0,0,0,0));
	while(!pq.empty()){
		par now=pq.top();
		pq.pop();
		now.min*=(-1);
		if(memo[now.second.second.second][now.second.second.first])continue;
		memo[now.second.second.second][now.second.second.first]=true;
		res=max(res,now.second.first);
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				if(j!=now.second.second.second){
					if(!(now.second.second.first&(1<<i))&&now.min+m[j][i]<=T){
						pq.push(pb((now.min+m[j][i])*(-1),now.second.first+1,(now.second.second.first|(1<<i)),j));
					}
				}
			}
		}
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t;
		cin>>t;
		while(t--){
			memset(memo,0,sizeof(memo));
			cin>>n;
			res=0;
			for(int i=0;i<3;i++){
				for(int j=0;j<n;j++){
					cin>>m[i][j];
				}
			}
			solve();
			cout << res<<"\n";
		}
	}
