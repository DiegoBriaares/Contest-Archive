#include <bits/stdc++.h>
using namespace std;
#define MAX 200002
#define ll long long
ll r;
int n;
ll v[MAX];
vector<ll>arr;
set<int>posicion[MAX];
ll bit[MAX];
void update(int i,int x){
	while(i<MAX){
		bit[i]+=x;
		i+=(i&-i);
	}
}
ll query(int i){
	if(i<=0)return 0;
	ll res=0;
	while(i>0){
		res+=bit[i];
		i-=(i&-i);
	}
	return res;
}

int dist(int i, int j) {
    if(i <= j) return j - i + 1 - (query(j)-query(i-1));
    else return dist(1, j) + dist(i, n);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=n;i>=1;i--){
			cin>>v[i];
			arr.push_back(v[i]);
			posicion[v[i]].insert(i);
		}
		sort(arr.begin(),arr.end());
		int p=n;
		for(int i=0;i<n;i++){
			int x=arr[i];
			set<int>::iterator it=posicion[x].upper_bound(p);
	        if(it!=posicion[x].begin())it--;
	        if(*it>p)it=posicion[x].end(),it--;
	        int idx=*it;
	        posicion[x].erase(it);
			r+=dist(idx,p);
			update(idx,1);
			p=idx;
		}
		cout << r<<"\n";
	}
