#include <bits/stdc++.h>
using namespace std;
#define MAX 10002
int BIT[MAX];
void add(int i,int val,int n){
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
void update(int i, int x){
    for(;i<=MAX;i+=i&-i)
        BIT[i]+=x;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t;
		cin>>t;
		for(int rep=0;rep<t;rep++){
			memset(BIT,0,sizeof(BIT));
			int i,j,k,n,u,g,h,y;
			cin>>n>>u;
			for(i=0;i<u;i++){
				cin>>g>>h>>y;
				g++;
				h++;
				while(g<=h){
					add(g,y,n);
					g++;
				}
			}
			cin>>k;
			for(i=0;i<k;i++){
				cin>>g;
				g++;
				cout << query(g)-query(g-1)<<"\n";
			}	
		}
	}
