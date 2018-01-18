#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
ll n,k;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		if(n%k==0)n+=k;
		else n+=(k-(n%k));
		cout << n<<"\n";
	}
