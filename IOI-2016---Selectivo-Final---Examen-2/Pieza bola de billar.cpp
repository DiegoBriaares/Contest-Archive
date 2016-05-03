#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>m;
		n--;
		m--;
		cout << __gcd(n,m)+1<<"\n";
	}
