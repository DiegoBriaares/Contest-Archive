#include <bits/stdc++.h>
using namespace std;
int memo[27][250];
string v;
int dp(int i,int an){
	if(i==v.size())return 1;
	if(memo[i][an])return memo[i][an];
	int uso=0;
	for(int j=i;j<v.size();j++){
		uso+=(v[j]-'0');
		if(uso>=an){
			memo[i][an]+=dp(j+1,uso);
		}
	}
	return memo[i][an];
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t=1;
		while(cin>>v&&v!="bye"){
			memset(memo,0,sizeof(memo));
			cout <<t++<<". "<<dp(0,0)<<"\n";
		}
	}
