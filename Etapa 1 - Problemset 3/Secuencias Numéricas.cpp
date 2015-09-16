#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000001
	long v[MAXN],v2[MAXN];
	stack<long>p;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		long i,j,n,uso,r,c;
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>v[i];
			v2[i]=-1;
			if(i==1){
				p.push(i);
			}
			else {
				uso=v[i];
				if(!p.empty())
				j=p.top();
				while(uso>v[j]&&!p.empty()){
					v2[j]=i;
					p.pop();
					if(!p.empty())
					j=p.top();
				}
				p.push(i);
			}
		}
		for(i=1;i<=n;i++){
			cout << v2[i] << " ";
		}
	}
