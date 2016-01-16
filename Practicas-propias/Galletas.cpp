#include <bits/stdc++.h>
using namespace std;
int memo[188][151][51];
int dp(int n,int a,int b,int c){
	if(n==0)return 0;
	if(!memo[n][b][c]){
		int mini=(1<<20);
		if(a-8>=0)mini=min(mini,dp(n-1,a-8,b,c)+8);
		if(a-3>=0&&b-1>=0)mini=min(mini,dp(n-1,a-3,b-1,c)+4);
		if(b-2>=0)mini=min(mini,dp(n-1,a+2,b-2,c)+2);
		if(a-3>=0&&c-1>=0)mini=min(mini,dp(n-1,a-3,b+1,c-1)+4);
		if(c-1>=0)mini=min(mini,dp(n-1,a+2,b,c-1)+1);
		memo[n][b][c]=mini;
	}
	return memo[n][b][c];
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int n;
		cin>>n;
		int a,b,c;
		cin>>a>>b>>c;
		if(a+(b*5)+(c*10)>=(8*n))cout << dp(n,a,b,c)<<"\n";
		else cout <<-1;
	}
