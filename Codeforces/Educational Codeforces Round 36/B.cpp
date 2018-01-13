#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
#define INF 999999999999999999
ll res;
ll n,k,l,r,pos;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>pos>>l>>r;
		if(l==1&&r==n){
			cout << "0\n";
			return 0;
		}
		res=min(abs(pos-l),abs(pos-r))+(r-l);
		if(l==1)res=abs(pos-r)+1;
		else if(r==n)res=abs(pos-l)+1;
		else res+=2;
		cout << res<<"\n";
	}
