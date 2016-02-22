#include <bits/stdc++.h>
using namespace std;
int v[9];
bool ok=false,memo[9];
void dfs(int i,int s,vector<int>x,int m){
	if(s==100&&m==7){
		for(int j=0;j<x.size();j++)cout << x[j]<<"\n";
		ok=true;
		return;
	}
	if(ok||i>=9||s>100||m>7)return;
	vector<int>uso;
	uso=x;
	uso.push_back(v[i]);
	dfs(i+1,s+v[i],uso,m+1);
	dfs(i+1,s,x,m);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		for(int i=0;i<9;i++)cin>>v[i];
		sort(v,v+9);
		vector<int>uso;
		dfs(0,0,uso,0);
	}
