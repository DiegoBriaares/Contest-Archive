#include <bits/stdc++.h>
using namespace std;
#define MAX 20002
#define ll long long
ll v[MAX],n;
//PORQUE DA 40 ETHAN?!!!!!!!!
map<pair<int,ll>,int>memo,memo2;
ll dp(int i,ll p){
	if(i==n)return 0;
	pair<int,int>uso=make_pair(i,p);
	if(memo[uso])return memo[uso];
	if(v[i]<p){
		return memo[uso]=(p-v[i])+(dp(i+1,v[i]+(p-v[i])));
	}
	return memo[uso]=dp(i+1,v[i]);
}
ll dp2(int i,ll p){
	if(p<0)return (1<<30);
	if(i==n)return 0;
	pair<int,int>uso=make_pair(i,p);
	if(memo2[uso])return memo2[uso];
	if(v[i]>p){
		return memo2[uso]=(v[i]-p)+(dp2(i+1,v[i]-(v[i]-p)));
	}
	return memo2[uso]=dp2(i+1,v[i]);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++)cin>>v[i];
		cout << min(dp(1,v[0]),dp2(1,v[0]))<<"\n";
	}
