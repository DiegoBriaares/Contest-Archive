#include <bits/stdc++.h>
using namespace std;
string v;
int n,q;
int a,b;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		while(cin>>v){
			cin>>q;
			n=v.size();
			for(int i=0;i<q;i++){
				cin>>a>>b;
				a--,b--;
				cout << v[(a+b)%n]<<"\n";
			}
		}
	}
