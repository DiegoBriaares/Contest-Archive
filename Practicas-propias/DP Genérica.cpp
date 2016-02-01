#include <bits/stdc++.h>
using namespace std;
#define uli unsigned long long
#define li long long
map<pair<uli,int>,li>memo;
li dp(uli x,int p){
	const pair<uli,int> uso=make_pair(x,p);
	if(x==0)return 1;
	if(p<63&&((1ULL<<(p+2))-2)<x)return 0;
	//if(x+(1ULL<<p)<0)return 0;
	if(memo[uso])return memo[uso];
	memo[uso]+=(dp(x,p-1));
	if(x>=(1ULL<<p))memo[uso]+=(dp(x-(1ULL<<p),p-1));
	if(p<63&&x>=(1ULL<<(p+1)))memo[uso]+=dp(x-(1ULL<<(p+1)),p-1);
	return memo[uso];
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		uli n;
		cin>>n;
		cout << dp(n,63)<<"\n";
	}
