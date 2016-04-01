#include <bits/stdc++.h>
using namespace std;
#define MAX 102
char v[MAX];
int n,memo[MAX][52][2];
int dp(int i,int c,int s){
	if(i==n&&c>0)return -(1<<30);
	if(i==n)return 0;
	if(memo[i][c][s])return memo[i][c][s];
	if(v[i]=='T'&&c>0){
		return memo[i][c][s]=max((s==0?-1:1)+dp(i+1,c-1,s),dp(i+1,c,(s+1)%2));
	}
	if(v[i]=='F'&&c>0){
		return memo[i][c][s]=max(dp(i+1,c-1,(s+1)%2),(s==0?-1:1)+dp(i+1,c,s));
	}
	if(v[i]=='F'&&c==0){
			return memo[i][c][s]=(s==0?-1:1)+dp(i+1,c,s);
	}
	if(v[i]=='T'&&c==0){
			return memo[i][c][s]=dp(i+1,c,(s+1)%2);
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int i,c;
		cin>>n;
		for(i=0;i<n;i++){
			cin>>v[i];
		}
		cin>>c;
		if(v[0]=='T')cout << dp(0,c,0)<<"\n";
		else if(v[0]=='F')cout << dp(0,c,1)<<"\n";
	}
