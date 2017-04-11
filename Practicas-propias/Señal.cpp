#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
int q,n,x;
int v[MAX];
string r="";
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		memset(v,-1,sizeof(v));
		cin>>q>>n;
		while(q--){
			for(int i=0;i<n;i++){
				cin>>x;
				if(v[i]==-1)v[i]=x;
			}
		}
		for(int i=0;i<n;i++){
			if(v[i]==-1){
				cout << "-1\n";
				return 0;;
			}
			char m=(char)v[i];	
			r+=m;
		}
		cout << r<<"\n";
	}
