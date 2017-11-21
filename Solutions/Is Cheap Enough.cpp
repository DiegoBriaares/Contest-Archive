#include <bits/stdc++.h>
using namespace std;
#define MAX 500012
#define ll int
#define name second.first
#define low second.second
#define hight first
#define pos(k) distance(money.begin(),lower_bound(money.begin(),money.end(),k))
int n,q;
ll p[MAX];
ll TreeI[MAX];
ll TreeR[MAX];
vector<int>money;
pair<ll,pair<string,ll> >v[MAX];
void updateI(int i,int x){
	while(i<MAX){
		TreeI[i]+=x;
		i+=(i&-i);
	}
}
int queryI(int i){
	int r=0;
	while(i>0){
		r+=TreeI[i];
		i-=(i&-i);
	}
	return r;
}
void updateR(int i,int x){
	while(i<MAX){
		TreeR[i]+=x;
		i+=(i&-i);
	}
}
int queryR(int i){
	int r=0;
	while(i>0){
		r+=TreeR[i];
		i-=(i&-i);
	}
	return r;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i].name>>v[i].low>>v[i].hight;
			money.push_back(v[i].low);
			money.push_back(v[i].hight);
		}
		cin>>q;
		for(int i=0;i<q;i++){
			cin>>p[i];
			money.push_back(p[i]);
		}
		sort(money.begin(),money.end());
		money.erase(unique(money.begin(),money.end()),money.end());
		int c=1;
		for(int i=0;i<n;i++,c++){
			int in=pos(v[i].low)+1;
			int fin=pos(v[i].hight)+1;
			updateI(in,c);
			updateI(fin+1,-c);
			updateR(in,1);
			updateR(fin+1,-1);
		}
		for(int i=0;i<q;i++){
			int idx=queryR(pos(p[i])+1);
			if(idx==0)cout <<"NONE\n";
			else if(idx>1)cout <<"MULTIPLE\n";
			else {
				cout << v[queryI(pos(p[i])+1)-1].name<<"\n";
			}
		}
	}
