#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
#define INF 9999999999999
ll res;
ll n,k;
ll v[MAX];
string pos;
bool h[MAX];
vector<ll>places;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i];
		}
		cin>>pos;
		for(int i=1;i<=n;i++){
			bool act=false;
			if(pos[i-1]=='1')act=true;
			if(!act)places.push_back(i);
		}
		for(int i=0;i<places.size();i++){
			h[places[i]]=true;
		}
		int pos=1;
		vector<ll>acum;
		for(int i=1;i<=n;i++){
			if(h[i]){
				acum.clear();
				for(int j=pos;j<=i;j++){
					acum.push_back(v[j]);
				}
				sort(acum.begin(),acum.end());
				k=0;
				for(int j=pos;j<=i;j++,k++){
					if(j!=acum[k]){
						cout << "NO\n";
						return 0;
					}
				}
				pos=i+1;
			}
		}
		cout << "YES\n";
	}
