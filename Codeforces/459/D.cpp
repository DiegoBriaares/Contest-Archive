#include <bits/stdc++.h>
using namespace std;
#define MAX 102
int n,m;
int memo[MAX][MAX][MAX][3];
vector<pair<int,char> >edg[MAX];
bool dp(int i,int j,int wrd,bool p){
	if(memo[i][j][wrd][p]!=-1)return memo[i][j][wrd][p];
	int v=(p?i:j);
	bool win=false;
	for(int it=0;it<edg[v].size();it++){
		if(edg[v][it].second-'a'<wrd)continue;
		if(p&&!dp(edg[v][it].first,j,edg[v][it].second-'a',!p)){
			win=true;
			break;
		}
		if(!p&&!dp(i,edg[v][it].first,edg[v][it].second-'a',!p)){
			win=true;
			break;
		}
	}
	return memo[i][j][wrd][p]=win;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		memset(memo,-1,sizeof(memo));
		cin>>n>>m;
		for(int i=0;i<m;i++){
			int x,y;
			char aux;
			cin>>x>>y>>aux;
			edg[x].push_back(make_pair(y,aux));
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dp(i,j,0,1)){
					cout << "A";
				}
				else cout << "B";
			}
			cout << "\n";
		}
	}
