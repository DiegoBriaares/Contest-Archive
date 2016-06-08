#include <bits/stdc++.h>
using namespace std;
#define MAX 34
#define ll long long
ll v[MAX];
ll n;
ll r=(1<<30);
void solve(int i,ll a,ll b,ll m,ll m2){
	if(i==n){
		r=min(r,abs(a-b));
		return;
	}
	if(m<(n/2))solve(i+1,a+v[i],b,m+1,m2);
	if(m2<(n/2))solve(i+1,a,b+v[i],m,m2+1);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}	
		solve(0,0,0,0,0);
		cout << r<<"\n";
	}
