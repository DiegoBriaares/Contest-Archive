#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
ll n,res;
priority_queue<ll>mi,ma;
int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		mi.push(-x);
		ma.push(x);
	}
	while(1){
		ll a=ma.top();
		ll b=-mi.top();
		mi.pop();
		ma.pop();
		if(a-b<=1)break;
		res++;
		a--;b++;
		ma.push(a);
		mi.push(-b);
	}
	cout << res<<"\n";
}
