#include <bits/stdc++.h>
using namespace std;
#define MAX 102
#define ll long long
ll n,c;
bool h[3];
bool v[MAX][MAX];
char m[MAX][MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>c;
		for(int i=0;i<n;i++){
			for(int j=0;j<c;j++){
				cin>>m[i][j];
			}
		}
		bool ok=false;
		for(int i=1;i<c;i++){
			if(m[0][i]!=m[0][i-1])ok=true;
		}
		if(!ok){ //Alto
			if(n%3!=0){
				cout << "NO\n";
				return 0;
			}
			int idx=0;
			for(int k=0;k<3;k++){
				char x=m[idx][0];
				for(int i=0;i<(n/3);i++,idx++){
					for(int j=1;j<c;j++){
						if(m[idx][j]!=m[idx][j-1]||m[idx][j]!=x||m[idx][j-1]!=x){
							cout << "NO\n";
							return 0;
						}
					}
				}
			}
		}
		else { //Ancho
			for(int i=1;i<n;i++){
				if(m[i][0]!=m[i-1][0]){
					cout << "NO\n";
					return 0;	
				}
			}
			if(c%3!=0){
				cout << "NO\n";
				return 0;
			}
			int idx=0;
			for(int k=0;k<3;k++){
				char x=m[0][idx];
				for(int i=0;i<(c/3);i++,idx++){
					for(int j=1;j<n;j++){
						if(m[j][idx]!=m[j-1][idx]||m[j][idx]!=x||m[j-1][idx]!=x){
							cout << "NO\n";
							return 0;
						}
					}
				}
			}
		}
		cout << "YES\n";
	}
