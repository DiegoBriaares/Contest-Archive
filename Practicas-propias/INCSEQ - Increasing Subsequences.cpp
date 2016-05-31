#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
#define MOD 5000000
#define MAXK 52
ll n,k;
ll bit[MAXK][MAX];
void update(int i,ll j,ll x){
	j++;
	while(j<=MAX){
		bit[i][j]+=x;
		bit[i][j]%=MOD;
		j+=(j&-j);
	}
}
ll query(int i,ll j){
	if(i==0)return 1;
	j++;
	ll r=0;
	while(j>0){
		r+=bit[i][j];
		r%=MOD;
		j-=(j&-j);
	}
	return r;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		ll x;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>x;
			for(int j=1;j<=k;j++){
				update(j,x,query(j-1,x-1));
			}
		}
		/*for(int i=1;i<=k;i++){
			for(int j=1;j<=11;j++)cout << (query(i,j)-query(i,j-1))<<" ";
			cout <<"\n";
		}*/
		cout << query(k,MAX)%MOD<<"\n";
	}
