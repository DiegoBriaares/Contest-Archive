#include <bits/stdc++.h>
using namespace std;
int des(string v){
	int i=0,j=v.size(),s=0;
	while(i<j){
		s+=v[i];
		i++;
	}
	return s;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int n,k,t,uso,uso2,r=0,i=0,j,x,y;
		cin >>n;
		string v[n];
		bool m[n][n];
		string p;
		while(i<n){
			cin >>v[i];
			i++;
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cin >>m[i][j];
			}
		}
		i=0;
		cin>>k;
		while(i<k){
			cin >>p;
			j=0;
			while(j<n){
				if(v[j]==p){
					x=j;
					j=n;
				}
				j++;
			}
			cin>>p;
			j=0;
			while(j<n){
				if(v[j]==p){
					y=j;
					j=n;
				}
				j++;
			}
			cout << m[x][y] << "\n";
			i++;
		}
	}
