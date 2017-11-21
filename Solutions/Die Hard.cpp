#include <bits/stdc++.h>
using namespace std;
int memo[1002][1002];
int s[]={3,-5,-20};
int ar[]={2,-10,5};
int dp(int uso,int h,int a){
	if(h<=0||a<=0)return -1;
	if(memo[h][a])return memo[h][a];
	int r=0;
	for(int i=0;i<3;i++){
		if(i!=uso)r=max(r,1+dp(i,h+s[i],a+ar[i]));
	}
	return memo[h][a]=r;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t,r,h,a;
		cin>>t;
		while(t--){
			memset(memo,0,sizeof(memo));
			cin>>h>>a;
			r=dp(-1,h,a);
			cout << r<<"\n";	
		}
	}
