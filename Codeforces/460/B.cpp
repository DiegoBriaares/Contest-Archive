#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
#define INF 9999999999999
ll n,k;
bool ok;
bool pos(ll x){
	ll s=0;
	while(x>0){
		s+=(x%10);
		x/=10;
		if(s>10)return false;
	}
	if(s==10)return true;
	return false;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0,j=19;i<n;j++){
			if(pos(j))k=j,i++;
		}
		cout << k<<"\n";
	}
