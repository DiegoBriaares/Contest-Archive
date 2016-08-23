#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define par pair<ll,ll> 
#define mp make_pair
ll n;
ll bfs(){
	map<ll,bool>memo;
	queue<par > cola;
	par in=mp(n,0);
	cola.push(in);
	while(!cola.empty()){
		par now =cola.front();
		cola.pop();
		if(now.first==0){
			return now.second;
		}
		if(memo[now.first])continue;
		memo[now.first]=true;
		par aux=mp(now.first-1,now.second+1);
		cola.push(aux);
		for(ll i=sqrt(now.first);i>1;i--){
			if(now.first%i==0){
				cola.push(mp(max(i,now.first/i),now.second+1));
			}
		}
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t;
		cin>>t;
		bool ok;
		while(t--){
			cin>>n;
			cout << bfs()<<"\n";
		}
	}
