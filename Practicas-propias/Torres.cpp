#include <bits/stdc++.h>
using namespace std;
#define MAX 5002
int v[MAX],n;
map<pair<int,int>,int>memo;
int dp(int i,int p){
	if(i==n)return 0;
	pair<int,int>uso=make_pair(i,p);
	if(memo[uso])return memo[uso];
	if(v[i]<p){
		int uso2=v[i],j,r=0;
		for(j=i+1;uso2<p&&j<n;j++){
			uso2+=v[j];
			r++;
		}
		if(j==n&&uso2<p)return memo[uso]=1+dp(i+1,p+v[i]);
		else if(uso2>=p){
			return memo[uso]=min(r+dp(j,uso2),1+dp(i+1,p+v[i]));
		}
	}
		return memo[uso]=dp(i+1,v[i]);
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
