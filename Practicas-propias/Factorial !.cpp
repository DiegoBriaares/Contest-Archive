#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define MAXN 9
int v[MAXN];
int memo[MAX][MAXN];
int dp(int n,int i){
	if(n==0)return 0;
	if(n<0||i==0)return (1<<30);
	if(memo[n][i])return memo[n][i];
	return memo[n][i]=min(1+dp(n-v[i],i),min(1+dp(n-v[i],i-1),dp(n,i-1)));
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int n,i=1,j=1;
		cin>>n;
		while(i<9){
			v[i]=j;
			i++;
			j*=i;
		}
		cout << dp(n,8)<<"\n";
	}
