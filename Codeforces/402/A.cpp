#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
int n;
int r;
int h[MAX];
int v[MAX];
int v2[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			int j;
			cin>>j;
			v[j]++;
			h[j]++;
		}	
		for(int i=0;i<n;i++){
			int j;
			cin>>j;
			v2[j]++;
			h[j]++;
		}	
		for(int i=1;i<6;i++){
			if(h[i]%2!=0){
				cout << "-1\n";
				return 0;
			}
		}
		for(int i=1;i<6;i++){
			int aux=max(v[i],v2[i]);
			int aux2=min(v[i],v2[i]);
			r+=(abs((h[i]/2)-aux));
		}
		cout << r/2<<"\n";
	}
