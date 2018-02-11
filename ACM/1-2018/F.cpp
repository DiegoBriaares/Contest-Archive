#include <bits/stdc++.h>
using namespace std;
#define MAX 412
#define ll long double
int n,k;
map<pair<int,int>,ll>memo;
ll dp(int i,int j){
	if(!j)return (ll)i;
	pair<int,int>aux=make_pair(i,j);
	if(!memo[aux])memo[aux]=0.5L*(dp((i<n?i+1:i),j-1)+dp((i<n?i:i-1),j-1));
	return memo[aux];
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		cout <<setprecision(8)<<fixed<< dp(0,k)<<"\n";	
	}
