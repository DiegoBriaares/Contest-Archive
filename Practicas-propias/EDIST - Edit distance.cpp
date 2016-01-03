#include<bits/stdc++.h>
using namespace std;
#define MAX 2101
string str1,str2;
int memo[MAX][MAX];
int dp(int n,int m){
	if(n==0)return m;
	if(m==0)return n;
	if(memo[n][m])return memo[n][m];
	if(str1[n-1]==str2[m-1])return memo[n][m]=dp(n-1,m-1);
	return memo[n][m]=1+min(min(dp(n,m-1),dp(n-1,m)),dp(n-1,m-1));
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//sirve para el autocorrector
 	int t;
 	cin>>t;
	while(t--){
		memset(memo,0,sizeof(memo));
		cin>>str1>>str2;
		cout << dp(str1.size(),str2.size())<<"\n";
	}
}
