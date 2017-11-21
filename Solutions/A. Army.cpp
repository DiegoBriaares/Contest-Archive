#include <bits/stdc++.h>
using namespace std;
#define MAX 102
int v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int n,i,a,b,k=0;
		cin>>n;
		n--;
		for(i=0;i<n;i++){
			cin>>v[i];
		}
		cin>>a>>b;
		for(i=a-1;i<(b-1);i++)k+=v[i];
		cout <<k<<"\n";
	}
