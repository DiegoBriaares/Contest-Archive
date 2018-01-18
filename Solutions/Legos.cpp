#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
ll n;
ll res;
ll v[MAX];
stack<ll>pm,pM;
pair<ll,ll>mini[MAX];
pair<ll,ll>maxi[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i];
		}
		pm.push(1);
		pM.push(1);
		for(int i=2;i<=n;i++){
			while(!pm.empty()&&v[i]>v[pm.top()]){  // Ver el menor a la derecha.
			
				maxi[pm.top()].first=(i-pm.top())-1;
				pm.pop();
			}
			while(!pM.empty()&&v[i]<v[pM.top()]){  // Ver el mayor a la derecha.
				mini[pM.top()].first=(i-pM.top())-1;
				pM.pop();
			}
			pm.push(i);
			pM.push(i);
		}
		while(!pm.empty()){
			maxi[pm.top()].first=(n-pm.top());
			pm.pop();
		}
		while(!pM.empty()){
			mini[pM.top()].first=(n-pM.top());
			pM.pop();
		}
		pm.push(n);
		pM.push(n);
		for(int i=n-1;i>=1;i--){
			while(!pm.empty()&&v[i]>=v[pm.top()]){  // Ver el menor a la izq.
				maxi[pm.top()].second=(pm.top()-i)-1;
				pm.pop();
			}
			while(!pM.empty()&&v[i]<=v[pM.top()]){  // Ver el mayor a la izq.
				mini[pM.top()].second=(pM.top()-i)-1;
				pM.pop();
			}
			pm.push(i);
			pM.push(i);
		}
		while(!pm.empty()){
			maxi[pm.top()].second=(pm.top()-1);
			pm.pop();
		}
		while(!pM.empty()){
			mini[pM.top()].second=(pM.top()-1);
			pM.pop();
		}
		for(int i=1;i<=n;i++){
			res+=v[i]*(maxi[i].first+1)*(maxi[i].second+1);
			res-=v[i]*(mini[i].first+1)*(mini[i].second+1);
		}
		cout << res<<"\n";
	}
