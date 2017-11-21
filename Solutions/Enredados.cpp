#include <bits/stdc++.h>
using namespace std;
#define MAX 1500000
#define ll long long
int bit[MAX];
int memo[MAX];
int n;
ll r;
void update(int i,int x){
	while(i<=MAX){
		bit[i]+=x;
		i+=(i&-i);
	}
}
ll query(int i){
	ll x=0;
	while(i>0){
		x+=bit[i];
		i-=(i&-i);
	}
	return x;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		n/=2;
		int j;
		for(int i=1;i<=n;i++){
			cin>>j;
			j--;
			memo[j]=i;
		}
		ll uso=0;
		for(int i=0;i<n;i++){
			cin>>j;
			j--;
			r+=(uso-query(memo[j]));
			uso++;
			update(memo[j],1);
		}
		cout << r;
	}
