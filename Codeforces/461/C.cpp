#include <bits/stdc++.h>
using namespace std;
#define MAX 25000002
#define ll long long
#define MOD 1000000007
ll n,k;
ll MAXN=MAX;
map<ll,bool>memo;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		if(k>=n&&n>1){
			cout << "No\n";
			return 0;
		}
		if(n%2==0&&k>=4){
			cout << "No\n";
			return 0;
		}
		if(n%2==0&&k>=4){
			cout << "No\n";
			return 0;
		}
		for(int i=1;i<=min(k,MAXN);i++){
			ll aux=(n%i);
			if(memo[aux]){
				cout << "No\n";
				return 0;
			}
			memo[aux]=true;
		}
		cout << "Yes\n";
	}
