#include <bits/stdc++.h>
using namespace std;
#define MAX 2002
int v[MAX],memo[MAX][MAX],n;
int dp(int i,int m,int age){
	if(i>m)return 0;
	if(memo[i][m])return memo[i][m];
	return memo[i][m]=max((v[i]*age)+dp(i+1,m,age+1),(v[m]*age)+dp(i,m-1,age+1));
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int i,j;
		cin>>n;
		for(i=0;i<n;i++)cin>>v[i];
		cout << dp(0,n-1,1)<<"\n";
	}
