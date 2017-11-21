#include <bits/stdc++.h>
using namespace std;
int memo[102][10002][7],n,k,r=0;
int dp(int i,int s,int c){
	if(s==n&&c==k)return 1;
	if(c>=k||s>n||i>100)return 0;
	if(s+i*i>n)return 0;
//	if(memo[i][s][c])return memo[i][s][c];
	return dp(i+1,s,c)+dp(i,s+(i*i),c+1);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		cout << dp(1,0,0)<<"\n";
	}
