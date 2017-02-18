#include <bits/stdc++.h>
using namespace std;
#define MAX 10000002
#define MAXN 1000002
int dif;
int n,m,k;
int x,r,r2;
int h[MAX];
int idx[MAX];
pair<int,int> v[MAXN];
queue<int>cola;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>m>>k;
		for(int i=0;i<n;i++){
			cin>>x;
			if(!h[x])dif++;
			h[x]++;
			if(h[x]>k)r=-1;
		}
		for(int i=0;i<m;i++){
			cin>>v[i].first;
			v[i].second=(i+1);
			if(!idx[v[i].first])idx[v[i].first]=i+1;
		}
		if(r==-1){
			cout << -1<<"\n";
			return 0;
		}
		sort(v,v+m);
		int p=0;
		for(int i=0;i<MAX;i++){
			while(p<m&&v[p].first<i)p++;
			if(p>=m||i>v[m-1].first)break;
			if(h[i]<k){
				while(p<m&&h[i]<k&&i<=v[p].first){
					cola.push(v[p].second);
					h[i]++;
					p++;
				}
			}
			if(p>=m||i>v[m-1].first)break;
		}
		cout << cola.size()<<"\n";
		while(!cola.empty()){
			cout << cola.front()<<" ";
			cola.pop();
		}
	}
