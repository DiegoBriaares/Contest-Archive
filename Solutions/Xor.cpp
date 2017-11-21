#include <bits/stdc++.h>
using namespace std;
#define MAX (1<<21)
int n,t,r;
int v[MAX]={1};
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			int j;
			cin>>j;
			t^=j;
			r+=v[t];
			v[t]++;
		}
		cout << r<<"\n";
	}
