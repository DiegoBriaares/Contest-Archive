#include <bits/stdc++.h>
using namespace std;
#define MAX 21
#define a first
#define b second
int n;
char m[MAX][MAX];
int memo[MAX][MAX][MAX][MAX][4][4];
int memo2[MAX][MAX][MAX][MAX][4][4];
int memo3[MAX][MAX][MAX][MAX][4][4];
int memo4[MAX][MAX][MAX][MAX][4][4];
pair<int,int> new_mov(int c){
	if(c==0)return make_pair(-1,0);
	if(c==1)return make_pair(0,1);
	if(c==2)return make_pair(1,0);
	if(c==3)return make_pair(0,-1);
}
int dp(int i,int j,int x,int y,int f1,int f2){
	if(i==0&&j==n-1&&x==0&&y==n-1){
		return 0;
	}
	if(memo[i][j][x][y][f1][f2])return memo[i][j][x][y][f1][f2];
	memo[i][j][x][y][f1][f2]=(1<<30);
	//Vuelta a la izquierda.
	memo[i][j][x][y][f1][f2]=min(memo[i][j][x][y][f1][f2],1+dp(i,j,x,y,(f1+3)%4,(f2+3)%4));
	//Vuelta a la derecha.
	memo[i][j][x][y][f1][f2]=min(memo[i][j][x][y][f1][f2],1+dp(i,j,x,y,(f1+1)%4,(f2+1)%4));
	//Derecho.
	pair<int,int>aux1=new_mov(f1);
	pair<int,int>aux2=new_mov(f2);
	int c=0;
	if((i==0&&j==n-1)||i+aux1.a>=n||i+aux1.a<0||j+aux1.b<0||j+aux1.b>=n||m[i+aux1.a][j+aux1.b]=='H'){
		aux1=make_pair(0,0);
		c++;
	}
	if((x==0&&y==n-1)||x+aux2.a>=n||x+aux2.a<0||y+aux2.b<0||y+aux2.b>=n||m[x+aux2.a][y+aux2.b]=='H'){
		aux2=make_pair(0,0);
		c++;
	}
	if(c<2){
		memo[i][j][x][y][f1][f2]=min(memo[i][j][x][y][f1][f2],1+dp(i+aux1.a,j+aux1.b,x+aux2.a,y+aux2.b,f1,f2));
	}
	return memo[i][j][x][y][f1][f2];
}
int dp2(int i,int j,int x,int y,int f1,int f2){
	if(i==0&&j==n-1&&x==0&&y==n-1){
		return 0;
	}
	if(memo2[i][j][x][y][f1][f2])return memo2[i][j][x][y][f1][f2];
	memo2[i][j][x][y][f1][f2]=(1<<30);
	//Vuelta a la derecha.
	memo2[i][j][x][y][f1][f2]=min(memo2[i][j][x][y][f1][f2],1+dp2(i,j,x,y,(f1+1)%4,(f2+1)%4));
	//Vuelta a la izquierda.
	memo2[i][j][x][y][f1][f2]=min(memo2[i][j][x][y][f1][f2],1+dp2(i,j,x,y,(f1+3)%4,(f2+3)%4));
	//Derecho.
	pair<int,int>aux1=new_mov(f1);
	pair<int,int>aux2=new_mov(f2);
	int c=0;
	if((i==0&&j==n-1)||i+aux1.a>=n||i+aux1.a<0||j+aux1.b<0||j+aux1.b>=n||m[i+aux1.a][j+aux1.b]=='H'){
		aux1=make_pair(0,0);
		c++;
	}
	if((x==0&&y==n-1)||x+aux2.a>=n||x+aux2.a<0||y+aux2.b<0||y+aux2.b>=n||m[x+aux2.a][y+aux2.b]=='H'){
		aux2=make_pair(0,0);
		c++;
	}
	if(c<2){
		memo2[i][j][x][y][f1][f2]=min(memo2[i][j][x][y][f1][f2],1+dp2(i+aux1.a,j+aux1.b,x+aux2.a,y+aux2.b,f1,f2));
	}
	return memo2[i][j][x][y][f1][f2];
}
int dp3(int i,int j,int x,int y,int f1,int f2){
	if(i==0&&j==n-1&&x==0&&y==n-1){
		return 0;
	}
	if(memo3[i][j][x][y][f1][f2])return memo3[i][j][x][y][f1][f2];
	memo3[i][j][x][y][f1][f2]=(1<<30);
	//Derecho.
	pair<int,int>aux1=new_mov(f1);
	pair<int,int>aux2=new_mov(f2);
	int c=0;
	if((i==0&&j==n-1)||i+aux1.a>=n||i+aux1.a<0||j+aux1.b<0||j+aux1.b>=n||m[i+aux1.a][j+aux1.b]=='H'){
		aux1=make_pair(0,0);
		c++;
	}
	if((x==0&&y==n-1)||x+aux2.a>=n||x+aux2.a<0||y+aux2.b<0||y+aux2.b>=n||m[x+aux2.a][y+aux2.b]=='H'){
		aux2=make_pair(0,0);
		c++;
	}
	if(c<2){
		memo3[i][j][x][y][f1][f2]=min(memo3[i][j][x][y][f1][f2],1+dp3(i+aux1.a,j+aux1.b,x+aux2.a,y+aux2.b,f1,f2));
	}
	//Vuelta a la derecha.
	memo3[i][j][x][y][f1][f2]=min(memo3[i][j][x][y][f1][f2],1+dp3(i,j,x,y,(f1+1)%4,(f2+1)%4));
	//Vuelta a la izquierda.
	memo3[i][j][x][y][f1][f2]=min(memo3[i][j][x][y][f1][f2],1+dp3(i,j,x,y,(f1+3)%4,(f2+3)%4));
	return memo3[i][j][x][y][f1][f2];
}
int dp4(int i,int j,int x,int y,int f1,int f2){
	if(i==0&&j==n-1&&x==0&&y==n-1){
		return 0;
	}
	if(memo4[i][j][x][y][f1][f2])return memo4[i][j][x][y][f1][f2];
	memo4[i][j][x][y][f1][f2]=(1<<30);
	//Derecho.
	pair<int,int>aux1=new_mov(f1);
	pair<int,int>aux2=new_mov(f2);
	int c=0;
	if((i==0&&j==n-1)||i+aux1.a>=n||i+aux1.a<0||j+aux1.b<0||j+aux1.b>=n||m[i+aux1.a][j+aux1.b]=='H'){
		aux1=make_pair(0,0);
		c++;
	}
	if((x==0&&y==n-1)||x+aux2.a>=n||x+aux2.a<0||y+aux2.b<0||y+aux2.b>=n||m[x+aux2.a][y+aux2.b]=='H'){
		aux2=make_pair(0,0);
		c++;
	}
	if(c<2){
		memo4[i][j][x][y][f1][f2]=min(memo4[i][j][x][y][f1][f2],1+dp4(i+aux1.a,j+aux1.b,x+aux2.a,y+aux2.b,f1,f2));
	}
	//Vuelta a la izquierda.
	memo4[i][j][x][y][f1][f2]=min(memo4[i][j][x][y][f1][f2],1+dp4(i,j,x,y,(f1+3)%4,(f2+3)%4));
	return memo4[i][j][x][y][f1][f2];
	//Vuelta a la derecha.
	memo4[i][j][x][y][f1][f2]=min(memo4[i][j][x][y][f1][f2],1+dp4(i,j,x,y,(f1+1)%4,(f2+1)%4));
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		freopen("cownav.in", "r", stdin);
  		freopen("cownav.out", "w", stdout);
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>m[i][j];
			}
		}
		cout << min(min(dp(n-1,0,n-1,0,0,1),dp4(n-1,0,n-1,0,0,1)),min(dp2(n-1,0,n-1,0,0,1),dp3(n-1,0,n-1,0,0,1)))<<"\n";
	}
