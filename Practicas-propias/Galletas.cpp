#include <bits/stdc++.h>
using namespace std;
int memo[150][500][100][50];
int dp(int n,int a,int b,int c){
	if(a<0||b<0||c<0)return (1<<20);
	if(n==0)return 0;
	if(memo[n][a][b][c])return memo[n][a][b][c];
	return memo[n][a][b][c]=min(min(1+dp(n-1,a+2,b,c-1),4+dp(n-1,a-3,b-1,c)),min(8+dp(n-1,a-8,b,c),2+dp(n-1,a+2,b-2,c)));
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
