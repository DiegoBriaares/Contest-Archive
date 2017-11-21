#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,x,y,c;
ll f(ll z){
	return (z*z)+((z+1)*(z+1));
}
ll gauss(ll z){
	return ((z*(z+1))/2);
}
bool solve(ll d) {
    ll a =max(0ll, d - (n - (y + 1)));
    ll b  = max(0ll, d - (n - (x + 1)));
    ll a2 = max(0ll, d - y);
    ll b2   = max(0ll, d - x);
 
    ll x1 = a * a;
    ll x2 = b * b;
    ll x3  = b2  * b2;
    ll x4 = a2 * a2;
    ll mid = f(d) - x3 - x2 - x1 - x4;
 
    ll nw = max(0ll, a - (x + 1));
    ll ne = max(0ll, a - (n - x));
    ll se = max(0ll, a2 - (n - x));
    ll sw = max(0ll, a2 - (x + 1));
    mid += gauss(nw) + gauss(ne) + gauss(se) + gauss(sw);
    return mid >= c;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>x>>y>>c;
		x--,y--;
		ll in=0,fin=n*3,mid;
		while(in<fin){
			mid=in+(fin-in)/2;
			if(solve(mid)){
				fin=mid;
			}
			else in=mid+1;
		}
		cout <<in<<"\n";
	}
