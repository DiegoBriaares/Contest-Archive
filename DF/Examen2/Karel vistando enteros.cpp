#include <bits/stdc++.h>
using namespace std;
#define MAX 302
#define llu unsigned long long
int n,l[MAX],c[MAX],r=(1<<30),flag=0;
map<pair<int,int>,int>memo;
int dp(int i,int s){
	pair<int,int>uso;
if(s==1){
    flag=1;
    return 0;
}
uso=make_pair(i,s);
if(i>=n)return (1<<30);
if(memo.count(uso))return memo[uso];
 return memo[uso]=min(dp(i+1,__gcd(s,l[i]))+c[i],dp(i+1,s));
}
	int main (){
		cin>>n;
		int i,j;
		for(i=0;i<n;i++){
			cin>>l[i];
		}
		for(i=0;i<n;i++){
			cin>>c[i];
			if(l[i]==1){
				r=min(r,c[i]);
				flag=1;
			}
		}
		for(i=0;i<n;i++){
			r=min(r,dp(i+1,l[i])+c[i]);
		}
		if(flag==0)cout <<-1;
		else cout <<r;
	}
