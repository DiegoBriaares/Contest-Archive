#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
int v[MAX],memo[MAX][MAX];
int dp(int i,int n){
	if(i>=n)return 0;
	if(memo[i][n])return memo[i][n];
	return memo[i][n]=max(v[i]+dp(i+(v[n]>v[i+1]?1:2),n-(v[n]>v[i+1]?1:0)),v[n]+dp(i+(v[n-1]>v[i]?0:1),n-(v[n-1]>v[i]?2:1)));
}
	int main (){
		int i,n,m,t=1;
		cin>>n;
		while(n!=0){
			m=0;
			memset(memo,0,sizeof(memo));
		for(i=0;i<n;i++){
			cin>>v[i];
			m+=v[i];
		}
		int r=dp(0,n-1);
		m-=r;
		cout <<"In game "<<t<<", the greedy strategy might lose by as many as "<<r-m<<" points.\n";
		t++;
		cin>>n;
		} 
	}
