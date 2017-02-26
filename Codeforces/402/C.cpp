#include <bits/stdc++.h>
using namespace std;
#define MAX 300002
int n,k;
int r;
int v[MAX];
int v2[MAX];
pair<int,int> prices[MAX];
vector<int>dis;
map<int,bool>memo;
int idx;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		for(int i=0;i<n;i++){
			cin>>v2[i];
			prices[i].first=(v[i]-v2[i]);
			prices[i].second=i;
			if(v[i]<=v2[i]){
				dis.push_back(i);
			}
		}
		int i=0,j=0;
		for(;i<dis.size();i++){
			r+=v[dis[i]];
			memo[dis[i]]=true;
		}
		sort(prices,prices+n);
		while(i<k&&j<n){
			if(!memo[prices[j].second]){
					r+=v[prices[j].second];
					i++;
				}
				j++;
		}
		for(;i<n;j++){
			if(!memo[prices[j].second]){
					r+=v2[prices[j].second];
					i++;
				}
		}
		cout << r<<"\n";
	}
