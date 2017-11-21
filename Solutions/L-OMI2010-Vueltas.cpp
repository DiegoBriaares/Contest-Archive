#include <bits/stdc++.h>
using namespace std;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int n,uso,uso2,i,j,k,q=0,w=0,r,c;
		cin>>r>>c;
		int m2[r][c];
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				cin>>m2[i][j];
			}
		}
		cin>>n;
		char b;
		for(i=0;i<n;i++){
			cin>>b;
			if(b=='V'){
				q++;
			}
			else {
				w++;
			}
		}
		if(q%2!=0){
			for(i=0,uso=r-1;i<r/2;i++,uso--){
				for(j=0;j<c;j++){
					swap(m2[uso][j],m2[i][j]);
				}
			}
		}
		if(w%2!=0){
			for(i=0;i<r;i++){
				for(j=0,uso=c-1;j<c/2;j++,uso--){
					swap(m2[i][uso],m2[i][j]);
				}
			}
		}
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				cout << m2[i][j] << " ";
			}
			cout << "\n";
		}
	}
