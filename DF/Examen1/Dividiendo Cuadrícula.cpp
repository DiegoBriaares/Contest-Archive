#include <bits/stdc++.h>
using namespace std;
#define MAX 102
int n,x,y;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t,r=0;
		cin>>t;
		while(t--){
			cin>>n>>x>>y;
			r=0;
			if(x>(n/2)+1||x<(n/2))r++;
			if(y>(n/2)+1||y<(n/2))r++;
			if(r>0)cout <<"YES\n";
			else cout << "NO\n";
		}
	}
