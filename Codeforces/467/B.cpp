#include <bits/stdc++.h>
using namespace std;
#define MAX 2000009
#define ll long long
ll p,y;
bool prime(ll x){
	ll y=sqrt(x)+1;
	y=min(y,p);
	while(y>1){
		if(x%y==0){
			return false;
		}
		y--;
	}
	return true;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>p>>y;
		while(y>p){
			if(prime(y)){
				cout <<y<<"\n";
				return 0;
			}
			y--;
		}
		cout << "-1\n";
	}
