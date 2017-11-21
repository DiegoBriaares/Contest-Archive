#include <bits/stdc++.h>
using namespace std;
#define MAX 10 
bool m[MAX][MAX];
bool r[MAX][MAX];
bool v[MAX];
bool ok=false;
void res(){
	for(int i=1;i<=8;i++){
			for(int j=1;j<=8;j++){
				if(r[i][j])cout << i<<" "<<j<<"\n";
			}
		}
}
bool check(int a,int b){
	if(ok)return false;
		for(int i=1;i<=8;i++){
			for(int j=1;j<=8;j++){
				if(m[i][j]&&i==a||m[i][j]&&j==b||m[i][j]&&(a-b)==(i-j)||m[i][j]&&(a+b)==(i+j))return false;
			}
		}
		return true;
	}
bool solve(int i){
	if(i==9){
		ok=true;
		return true;
	}
	if(v[i]){
		for(int j=1;j<=8;j++){
			if(check(i,j))return false;
		}
		return solve(i+1);
	}
	for(int j=1;j<=8;j++){
		if(check(i,j)){
			m[i][j]=true;
			if(solve(i+1)){
				v[i]=true;
				r[i][j]=true;
				return true;
			}
			m[i][j]=false;
		}
	}
	return false;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int t,a,b;
		cin>>t;
		while(t--){
			cin>>a>>b;
			m[a][b]=true;
			r[a][b]=true;
			v[a]=true;
		}
		int uso=solve(1);
		if(ok)res();
		else cout <<0;
	}
