#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
int BIT[MAX],v[MAX],n;
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
		cin>>n;
		int i,g,h,j,k;
		for(i=0;i<n;i++){
			cin>>g>>h;
			j=query(g);
			k=query(h);
			cout << (j+k-v[g]-v[h])<<"\n";
			v[g]=j;
			v[h]=k;
			update(g+1,1);
			update(h,-1);
		}
	}
