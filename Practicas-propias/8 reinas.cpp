#include <bits/stdc++.h>
using namespace std;
int n,a,b;
bool ok=false;
bool m[9][9];
bool danger(int v[],int j,int i){
	memset(m,false,sizeof(m));
	for(int k=1;k<=8;k++){
		if(k!=j)m[v[k]][k]=true;
	}
	for(int k=i;k>0;k--){   //Vertical abajo
		if(m[k][j])return false;
	}
	for(int k=i;k<9;k++){	//Vertical arriba
		if(m[k][j])return false;
	}
	for(int k=j;k<9;k++){	//Horizontal derecha
		if(m[i][k])return false;
	}
	for(int k=j;k>0;k--){	//Horizontal izquierda
		if(m[i][k])return false;
	}
	for(int k=i,k2=j;k<9&&k2<9;k++,k2++){	//Diagonal abajo derecha
		if(m[k][k2])return false;
	}
	for(int k=i,k2=j;k>0&&k2<9;k--,k2++){	//Diagonal arriba derecha
		if(m[k][k2])return false;
	}
	for(int k=i,k2=j;k<9&&k2>0;k++,k2--){	//Diagonal abajo izquierda
		if(m[k][k2])return false;
	}
	for(int k=i,k2=j;k>0&&k2>0;k--,k2--){	//Diagonal arriba izquierda
		if(m[k][k2])return false;
	}
	return true;
}
void solve(int i,int v[]){
	if(ok)return;
	if(i==9){
		ok=true;
		for(int j=1;j<=8;j++){
			cout << v[j]<<" "<<j<<"\n";
		}
		return;
	}
	if(v[i]){
		if(danger(v,i,v[i]))solve(i+1,v);
		return;
	}
	for(int j=1;j<=8;j++){
		if(danger(v,i,j)){
			v[i]=j;
			solve(i+1,v);
			v[i]=0;
		}
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);	
		int v[9];
		memset(v,0,sizeof(v));
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a>>b;
			if(danger(v,b,a))v[b]=a;
			else {
				cout << 0<<"\n";
				return 0;
			}
		}
		solve(1,v);
		if(!ok)cout << 0<<"\n";
	}
