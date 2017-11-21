#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
int v[MAX];
int n,k;
priority_queue<pair<int,int> >cola;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i];
		}
		cin>>k;
		for(int i=1;i<=n;i++){
			cola.push(make_pair(v[i],i));
			if(i>=k){
				while(cola.top().second<(i-k)+1){
					cola.pop();
				}
				cout << cola.top().first<<" ";
			}
		}
	}
