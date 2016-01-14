#include <bits/stdc++.h>
using namespace std;
int v[]={50,25,10,5,1},n;
unsigned long long memo[30002][5];
unsigned long long dp(int k,int i){
	if(k==0)return 1;
	if(k<0||i>4)return 0;
	if(memo[k][i])return memo[k][i];
	return memo[k][i]=dp(k-v[i],i)+dp(k-v[i+1],i+1)+dp(k-v[i+2],i+2)+dp(k-v[i+3],i+3)+dp(k-v[i+4],i+4);
}
	int main (){
		while(cin>>n){
			unsigned long long r=dp(n,0);
			if(r==1)cout <<"There is only 1 way to produce "<<n<<" cents change.\n";
			else cout <<"There are "<<r<<" ways to produce "<<n<<" cents change.\n";
		}
	}
