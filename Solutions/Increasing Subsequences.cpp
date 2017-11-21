#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define MOD 5000000
int BIT[52][MAX],n,k, uso;
void add(int i,int j,int val){
	j++;
	while(j<=MAX){
		BIT[i][j]+=(val);
		BIT[i][j]%=MOD;
		j+=(j&-j);
	}
}
int query(int i,int j){
	if(i==0) return 1;
	j++;
	int suma=0;
	while(j>0){
		suma+=(BIT[i][j]);
		suma%=MOD;
		j-=(j&-j);
	}
	return suma;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>uso;
			for(int j=1; j<=k; j++){
				add(j,uso,query(j-1,uso-1));	
			}
		}
		/*
		for(int j=0; j<=k; j++){
			for(int i=0;i<=21; i++)
				cout<<query( j,i )-query(j,i-1)<<" ";
			cout<<endl;
		}*/
		int res=query(k,100000);
		cout << res<<"\n";
	}
