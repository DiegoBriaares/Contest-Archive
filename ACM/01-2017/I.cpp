#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
int n,k,t;
pair<string,int>v[4*MAX];
priority_queue<pair<int,int> >cola;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>t;
		while(t--){
			cin>>n>>k;
			for(int i=n-1;i>=0;i--){
				cin>>v[i].first>>v[i].second;
				cola.push(make_pair(v[i].second*(-1),i));
			}
			for(int i=0;i<k;i++){
				int x=cola.top().first*(-1),idx=cola.top().second;
				cout << x <<" "<<v[idx].first<<"\n";
				x+=v[idx].second;
				cola.pop();
				cola.push(make_pair((x*(-1)),idx));
			}
			while(!cola.empty())cola.pop();
		}
	}
