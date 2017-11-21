#include <bits/stdc++.h>
using namespace std;
#define MAX 10002
int bit[MAX];
void update(int i,int v){
	while(i<=MAX){
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
		int t,a,b,c,n;
		for(cin>>t;t--;){
			memset(bit,0,sizeof(bit));
			cin>>c>>n;
			for(int i=0;i<n;i++){
				cin>>a>>b>>c;
				update(++a,c);
				update(++b+1,-c);
			}
			cin>>n;
			for(int i=0;i<n;i++){
				cin>>a;
				cout << query(++a)<<"\n";
			}
		}
	}
