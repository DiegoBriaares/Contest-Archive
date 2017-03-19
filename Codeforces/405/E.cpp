#include <bits/stdc++.h>
using namespace std;
#define MAX 77
int n;
string arr;
int memo[MAX][MAX][MAX][3];
vector<pair<int,int> >V,K,X;
int dp(int v,int k,int x,int pas){
	int pos=v+k+x;
	if(pos==n)return 0;
	if(memo[v][k][x][pas]!=-1)return memo[v][k][x][pas];
	memo[v][k][x][pas]=(1<<30);
	if(v<V.size()){
		memo[v][k][x][pas]=min(memo[v][k][x][pas],dp(v+1,k,x,0)+abs(V[v].first-k)+abs(V[v].second-x));
	}
	if(k<K.size()&&pas){
		memo[v][k][x][pas]=min(memo[v][k][x][pas],dp(v,k+1,x,1)+abs(K[k].first-v)+abs(K[k].second-x));
	}
	if(x<X.size()){
		memo[v][k][x][pas]=min(memo[v][k][x][pas],dp(v,k,x+1,2)+abs(X[x].first-v)+abs(X[x].second-k));
	}
	return memo[v][k][x][pas];
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		memset(memo,-1,sizeof(memo));
		cin>>n;
		cin>>arr;
		for(int i=0;i<n;i++){
			if (arr[i] == 'V') V.push_back(make_pair(K.size(), X.size()));
        	else if (arr[i] == 'K') K.push_back(make_pair(V.size(), X.size()));
        	else X.push_back(make_pair(V.size(), K.size()));
		}
		cout << dp(0,0,0,2)/2<<"\n";
	}
