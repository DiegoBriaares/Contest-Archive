#include <bits/stdc++.h>
using namespace std;
#define MAX 2000002
int n,x,s=0;
int bit[2*MAX];
void update(int i,int v){
	while(i<MAX){
		bit[i]+=v;
		i+=(i&-i);
	}
}
int query(int i){
	int r=0;
	while(i>0){
		r+=bit[i];
		i-=(i&-i);
	}
	return r;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x;
			update(s+1,i);
			update(s+x+1,-i);
			s+=x;
		}
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>x;
			cout << query(x)<<"\n";
		}
	}
