#include <bits/stdc++.h>
using namespace std;
#define MAX 1102
#define ll long long
ll n,k;
vector<ll>edg[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<n;i++){
			int a;
			cin>>a;
			edg[a].push_back(i+1);
			
		}
		for(int i=1;i<=n;i++){
			if(edg[i].size()>0){
				int ans=0;
				for(int j=0;j<edg[i].size();j++){
					if(edg[i][j]==i)continue;
					if(edg[edg[i][j]].size()==0)ans++;
				}
				if(ans<3){
					cout << "No\n";
					return 0;
				}
			}
		}
		cout << "Yes\n";
	}
