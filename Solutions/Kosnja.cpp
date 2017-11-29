#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
#define ll long long
ll q,n,m;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>q;
		while(q--){
			cin>>n>>m;
			ll res=((m-2)*2)+2;
			res=min(res,((n-2)*2)+2);
			res=min(res,(((m/2)-1)*4)+3+(m/2?1:0));
			res=min(res,(((n/2)-1)*4)+3+(n/2?1:0));
			if(n==2||m==2)res=2;
			if(n==1||m==1)res=0;
			cout << res<<"\n";
		}
	}
