#include <bits/stdc++.h>
using namespace std;
#define MAX 10002
int BIT[MAX],n;
void add(int i,int val){
	while(i<=n){
		BIT[i]+=val;
		i+=(i&-i);
	}
}
int query(int i){
	int suma=0;
	while(i>0){
		suma+=BIT[i];
		i-=(i&-i);
	}
	return suma;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
			int i,j,k,u,g,h,y;
			cin>>n>>u;
			for(i=0;i<u;i++){
				cin>>g>>h>>y;
				while(g<=h){
					add(g,y);
					g++;
				}
			}
			cin>>k;
			for(i=0;i<k;i++){
				cin>>g;
				cout << query(g)-query(g-1)<<"\n";
			}	
	}
