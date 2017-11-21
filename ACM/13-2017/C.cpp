#include <bits/stdc++.h>
using namespace std;
#define MAX 10002
#define ll long long
ll n,k;
ll v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int S;
		char a;
		while(cin>>S){
			cin>>a;
			if(S==1)cout<<1<<"\n";
				else {
					if(a=='K')cout<<4<<"\n";
					else {
						if(a=='N'){
							if(S>2)cout<<2<<"\n";
							else cout<<1<<"\n";
						}
						else cout<<S<<"\n";
					}
				}
		}
	}
