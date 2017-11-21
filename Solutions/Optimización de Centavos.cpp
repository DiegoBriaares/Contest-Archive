#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001
int memo[MAX][20],n,v[MAX],uso2;
int dp(int i,int d,int s,int t){
	if(i==n-1&&n==5)return s;
	if(i==n){
	return s;
	}
	if(d<0)return (1<<22);
	//cout << "r: "<<i<<" "<<d<<" "<<s<<" "<<t<<"\n";
	if(memo[i][d])return memo[i][d];
	int uso=s+v[i];
	if(d>0)memo[i][d]=min(dp(i+1,d,uso,t),(uso+((uso%10)<=4?-(uso%10):(10-(uso%10))))+dp(i+1,d-1,0,t+(uso+((uso%10)<=4?-(uso%10):(10-(uso%10))))));
	else memo[i][d]=dp(i+1,d,uso,t);
	uso=memo[i][d];
	if((uso%10)<=4)uso-=(uso%10);
	else uso+=(10-(uso%10));
	return uso;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int d,uso=0;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>v[i];
			uso+=v[i];
		}
		uso2=uso;
		if(d>0)cout <<dp(0,d,0,0)<<"\n";
		else {
			if((uso%10)<=4)uso-=(uso%10);
			else uso+=(10-(uso%10));
			cout << uso;
		}
	}
