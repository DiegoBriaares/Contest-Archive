#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
ll n;
ll a,b;
ll ma,r;
ll bit[MAX];
bool ok;
void update(int i,ll x){
	while(i<=MAX){
		bit[i]+=x;
		i+=(i&-i);
	}
}
ll query(int i){
	ll r=0;
	while(i>0){
		r+=bit[i];
		i-=(i&-i);
	}
	return r;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		int x,y;
		while(n--){
			cin>>a>>b;
			ma=max(ma,b);
			update(a,1);
			update(b,-1);	
		}
		for(int i=1;i<=MAX;i++){
			r=max(r,query(i));
		}
		cout << r<<"\n";
		for(int i=1;i<=MAX;i++){
			if(query(i)==r&&!ok){
				ok=true;
				x=i;
			}
			if(query(i)!=r&&ok){
				y=i;
				ok=false;
				if(x!=y)cout << x<<" "<<y<<"\n";
			}
		}
	}
