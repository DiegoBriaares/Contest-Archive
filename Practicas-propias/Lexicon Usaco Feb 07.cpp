#include <bits/stdc++.h>
using namespace std;
#define MAX 2002
int n,m;
string v;
int dp[MAX];
vector<string>dic;
void solve(int pos,int idx){
	string aux=dic[idx];
	int p=0,r=0,i=pos;
	while(p<aux.size()){
		while(v[i]!=aux[p]){
			i++,r++;
			if(i>=n)return;
		}
		i++;
		p++;
	}
	if(dp[pos]+r<dp[i])dp[i]=dp[pos]+r;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>m>>n;
		cin>>v;
		for(int i=0;i<m;i++){
			string aux;
			cin>>aux;
			dic.push_back(aux);
		}
		for(int i=0;i<=n;i++)dp[i]=i;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(dic[j].size()+i<=n){
					if(dic[j][0]==v[i]){
						solve(i,j);
					}
				}
			}
			if(dp[i]+1<dp[i+1])dp[i+1]=dp[i]+1;
		}
		cout << dp[n]<<"\n";
	}
