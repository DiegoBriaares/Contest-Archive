#include <bits/stdc++.h>
using namespace std;
#define MAXi 502
#define MAXj 502
int BIT[MAXi][MAXj];
void addx(int i,int j,int val){
	while(j<=MAXj){
		BIT[i][j]+=val;
		j+=(j&-j);
	}
}
void addy(int i,int j,int val){
	while(i<=MAXi){
		addx(i,j,val);
		i+=(i&-i);
	}
}
int queryx(int i,int j){
	int suma=0;
	while(j>0){
		suma+=BIT[i][j];
		j-=(j&-j);
	}
	return suma;
}
int query(int i,int j){
	int suma=0;
	while(i>0){
		suma+=queryx(i,j);
		i-=(i&-i);
	}
	return suma;
}
	int main (){
		int i,j,k=1;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++,k++){
				
			}
		}
	}
