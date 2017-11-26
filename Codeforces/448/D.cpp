#include <bits/stdc++.h>
using namespace std;
#define MAX 502
int n;
int v[MAX];
int memo[MAX][MAX];
int dp(int in,int fin){
	if(in>fin)return 1;
	if(memo[in][fin])return memo[in][fin];
	memo[in][fin]=(1<<30);
	if(v[in]==v[fin])memo[in][fin]=dp(in+1,fin-1);
	for(int i=in;i<fin;i++){
		memo[in][fin]=min(memo[in][fin],dp(in,i)+dp(i+1,fin));
	}
	return memo[in][fin];
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		cout << dp(0,n-1)<<"\n";
	}
