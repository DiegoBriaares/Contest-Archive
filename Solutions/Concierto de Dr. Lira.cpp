#include <bits/stdc++.h>
using namespace std;
#define MAX 52
int v[MAX],n,m,r=-1;
map<pair<int,int>,int>memo;
int dp(int i,int s){
	if(s<0||s>m)return -1;
	if(i==n)return s;
	pair<int,int>aux=make_pair(i,s);
	if(memo[aux])return memo[aux];
	int uso=-1;
	uso=max(uso,dp(i+1,s+v[i]));
	uso=max(uso,dp(i+1,s-v[i]));
	return memo[aux]=uso;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int in,i,j;
		cin>>n;
		for(i=0;i<n;i++)cin>>v[i];
		cin>>in>>m;
		cout <<dp(0,in);
	}
