#include <bits/stdc++.h>
using namespace std;
#define MAX 103

int M,N,S,X,Y;
char A[MAX][MAX];
bool posibles(int x, int y){
	if (x>=0&&x<M&&y>=0&&y<M) return true;
	else return false;
}

void dibuja1(int s, int x, int y){
	if (posibles(x-1,y)) A[y+1][x]=95;
	if (posibles(x,y)) A[y+1][x+1]=124;
	if (posibles(x+1,y)) A[y+1][x+2]=95;
	for (int i=1; i<=s; i++){
		if (posibles(x-1,y+i)) A[y+i+1][x]=47;
		if (posibles(x,y+i)) A[y+i+1][x+1]=124;
		if (posibles(x+1,y+i)) A[y+i+1][x+2]=92;
	}
	if (posibles(x,y+S+1)) A[y+S+2][x+1]=94;
}

void dibuja2(int x, int y){
	if (posibles(x-1,y)) A[y+1][x]=95;
	if (posibles(x,y)) A[y+1][x+1]=111;
	if (posibles(x+1,y)) A[y+1][x+2]=95;
}

int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (cin>>M>>N){
		for (int i=0; i<M+2; i++){
			for (int j=0; j<M+2; j++){
				if (i==0||i==M+1||j==0||j==M+1) A[i][j]=42;
				else A[i][j]=46;
			}
		}
		for (int i=0; i<N; i++){
			cin>>S>>X>>Y;
			if (S) dibuja1(S,X,Y);
			else dibuja2(X,Y);
		}
		for (int i=0; i<M+2; i++){
			for (int j=0; j<M+2; j++){
				cout<<A[M+1-i][j];
			}
			cout<<"\n";
		}
		cout<<"\n";
	}
	return 0;		
}
