#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAX 1002
string v;
int memo[MAX][MAX];
int dp(int i,int m){
	if(i>=m)return 0;
	if(memo[i][m])return memo[i][m];
	if(v[i]==v[m])return memo[i][m]=dp(i+1,m-1);
	return memo[i][m]=1+min(dp(i+1,m),dp(i,m-1));
}
string r;
void solve(int i,int j){
    if(i>j)return;
    if(v[i]==v[j])
    {
        r.pb(v[i]);
        solve(i+1,j-1);
        if(i!=j)r.pb(v[j]);
    }
    else if(dp(i,j)==dp(i+1,j)+1)
    {
        r.pb(v[i]);
        solve(i+1,j);
        r.pb(v[i]);
    }
    else if(dp(i,j)==dp(i,j-1)+1)
    {
         r.pb(v[j]);
         solve(i,j-1);
         r.pb(v[j]);
    }
}
	int main (){
		int n,i,j,k,g,h;
		while(cin>>v){
			r.clear();
			memset(memo,0,sizeof(memo));
			n=v.size();
			cout <<dp(0,n-1)<<" ";
			solve(0,n-1);
			cout <<r<<"\n";
		}
	}
