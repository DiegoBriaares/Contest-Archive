#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
#define MAXN 4000002
set<int>a,b;
int n,v[MAX],res[MAXN];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int i,j,k,g,h=0;
		cin>>n;
		for(i=0;i<n;i++){
			cin>>v[i];
		}
		for(i=0;i<n;i++){
			a.insert(j);
			for(set<int>::iterator it = a.begin();it!=a.end();it++){
				b.insert(*it |v[i]);
			}
			a=b;
			b.clear();
			for(set<int>::iterator it = a.begin();it!=a.end();it++){
				res[*it]++;
			}
		}
		for(i=0;i<=MAXN;i++){
			if(res[i]>0)h++;
		}
		cout << h<<"\n";
	}
