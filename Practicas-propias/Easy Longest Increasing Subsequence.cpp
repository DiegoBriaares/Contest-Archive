#include <bits/stdc++.h>
using namespace std;
#define MAX 22
int v[MAX],n,memo[MAX][500];
int dp(int i,int x){
	if(i==n)return 0;
	if(memo[i][x])return memo[i][x];
	if(v[i]>x){
		return memo[i][x]=max(dp(i+1,x),1+dp(i+1,v[i]));
	}
	else return memo[i][x]=dp(i+1,x);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		cout << dp(0,0)<<"\n";
	} 
