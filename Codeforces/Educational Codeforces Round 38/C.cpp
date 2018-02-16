#include <bits/stdc++.h>
using namespace std;
#define MAX 301002
#define ll long long
#define MOD 1000000007
bool ok;
ll n,k,x;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t;
		cin>>t;
		while(t--){
			cin>>x;
			ok=false;
			for(int i=1;i<=35000;i++){
				ll in=i,fin=1000000000,la=-1;
				while(in<=fin){
					ll mid=(in+fin)/2LL;
					if(((mid*mid)-x)==((mid/i)*(mid/i))){
						if(mid>=i){
							cout << mid<<" "<<i<<"\n";
							ok=true;
						}
						break;	
					}
					if(((mid*mid)-x)>((mid/i)*(mid/i))){
						fin=mid-1;
					}
					if(((mid*mid)-x)<((mid/i)*(mid/i))){
						in=mid+1;
					}
				}
				if(ok)break;
			}
			if(!ok)cout << "-1\n";
		}
	}
