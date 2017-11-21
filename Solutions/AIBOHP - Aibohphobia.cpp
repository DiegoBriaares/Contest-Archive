#include <bits/stdc++.h>
using namespace std;
#define MAX 6102
int memo[MAX][MAX];
string v;
int dp(int i,int j){
	if(i>=j)return 0;
	if(memo[i][j])return memo[i][j];
	if(v[i]==v[j])return memo[i][j]=dp(i+1,j-1);
	return memo[i][j]=1+min(dp(i+1,j),dp(i,j-1));
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t,rep;
		for(cin>>t,rep=0;rep<t;rep++){
			memset(memo,0,sizeof(memo));
			cin>>v;
			cout << dp(0,v.size()-1)<<"\n";
		}
	}
