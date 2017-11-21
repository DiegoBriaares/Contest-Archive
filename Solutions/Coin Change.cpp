#include <bits/stdc++.h>
using namespace std;
#define MAX 7500
int n,v[]={50,25,10,5,1},memo[5][MAX];
int dp(int i,int m){
	if(m==0)return 1;
	if(m<0)return 0;
	if(i>4)return 0;
	if(memo[i][m])return memo[i][m];
	return memo[i][m]=dp(i,m-v[i])+dp(i+1,m-v[i+1])+dp(i+2,m-v[i+2])+dp(i+3,m-v[i+3])+dp(i+4,m-v[i+4]);
}
	int main (){
		while(cin>>n){
			cout << dp(0,n)<<"\n";
		}
	}
