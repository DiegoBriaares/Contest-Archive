#include <bits/stdc++.h>
using namespace std;
#define P 107
#define MAX 1002
#define ll long long
#define MOD 1000000007
int n,c;
int res[10];
char m[MAX][MAX];
map<pair<ll,ll>,int>sols;
string a[7][7]={".",".",".",".",".",".",".",
					  ".",".",".",".",".",".",".",
					  ".",".",".",".",".",".",".",
					  ".",".","*","*","*",".",".",
					  ".",".",".",".","*",".",".",
					  ".",".",".",".",".",".",".",
					  ".",".",".",".",".",".","."};
					  
string b[7][7]={".",".",".",".",".",".",".",
					  ".",".",".",".",".",".",".",
					  ".",".",".","*",".",".",".",
					  ".","*","*","*","*",".",".",
					  ".",".",".",".",".",".",".",
					  ".",".",".",".",".",".",".",
					  ".",".",".",".",".",".","."};	
					  		  
string ca[7][7]={".",".",".",".",".",".",".",
					  ".",".",".","*",".",".",".",
					  ".",".","*","*","*",".",".",
					  ".",".",".","*",".",".",".",
					  ".",".",".",".",".",".",".",
					  ".",".",".",".",".",".",".",
					  ".",".",".",".",".",".","."};	
					  			  
string d[7][7]={".",".",".",".",".",".",".",
					  ".",".",".",".",".",".",".",
					  ".",".","*","*",".",".",".",
					  ".",".",".","*","*",".",".",
					  ".",".",".","*",".",".",".",
					  ".",".",".",".",".",".",".",
					  ".",".",".",".",".",".","."};	
					  
string e[7][7]={".",".",".",".",".",".",".",
					  ".",".",".",".",".",".",".",
					  ".",".","*","*",".",".",".",
					  ".",".",".","*",".",".",".",
					  ".",".",".","*","*",".",".",
					  ".",".",".",".",".",".",".",
					  ".",".",".",".",".",".","."};
int dx[4]={0,-1,1,0};
int dy[4]={1,0,0,-1};
ll h,h2;
bool memo[MAX][MAX];
void rotaA(){
	char aux[7][7];
	for(int i=0;i<7;i++){
		for(int j=0,k=6;j<7;j++,k--){
			aux[i][j]=a[k][i][0];
		}
	}
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			a[i][j][0]=aux[i][j];
		}
	}
}
void dfsA(int i,int j,int p){
	if(i>6||j>6||i<0||j<0||memo[i][j]||a[i][j][0]=='.')return;
	memo[i][j]=true;
	h*=P;
	h+=p;
	h%=MOD;
	h2*=P;
	h2+=p;
	for(int it=0;it<4;it++){
		dfsA(i+dx[it],j+dy[it],it+1);
	}
}

void rotaB(){
	char aux[7][7];
	for(int i=0;i<7;i++){
		for(int j=0,k=6;j<7;j++,k--){
			aux[i][j]=b[k][i][0];
		}
	}
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			b[i][j][0]=aux[i][j];
		}
	}
}
void dfsB(int i,int j,int p){
	if(i>6||j>6||i<0||j<0||memo[i][j]||b[i][j][0]=='.')return;
	memo[i][j]=true;
	h*=P;
	h+=p;
	h%=MOD;
	h2*=P;
	h2+=p;
	for(int it=0;it<4;it++){
		dfsB(i+dx[it],j+dy[it],it+1);
	}
}
void rotaC(){
	char aux[7][7];
	for(int i=0;i<7;i++){
		for(int j=0,k=6;j<7;j++,k--){
			aux[i][j]=ca[k][i][0];
		}
	}
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			ca[i][j][0]=aux[i][j];
		}
	}
}
void dfsC(int i,int j,int p){
	if(i>6||j>6||i<0||j<0||memo[i][j]||ca[i][j][0]=='.')return;
	memo[i][j]=true;
	h*=P;
	h+=p;
	h%=MOD;
	h2*=P;
	h2+=p;
	for(int it=0;it<4;it++){
		dfsC(i+dx[it],j+dy[it],it+1);
	}
}
void rotaD(){
	char aux[7][7];
	for(int i=0;i<7;i++){
		for(int j=0,k=6;j<7;j++,k--){
			aux[i][j]=d[k][i][0];
		}
	}
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			d[i][j][0]=aux[i][j];
		}
	}
}
void dfsD(int i,int j,int p){
	if(i>6||j>6||i<0||j<0||memo[i][j]||d[i][j][0]=='.')return;
	memo[i][j]=true;
	h*=P;
	h+=p;
	h%=MOD;
	h2*=P;
	h2+=p;
	for(int it=0;it<4;it++){
		dfsD(i+dx[it],j+dy[it],it+1);
	}
}
void rotaE(){
	char aux[7][7];
	for(int i=0;i<7;i++){
		for(int j=0,k=6;j<7;j++,k--){
			aux[i][j]=e[k][i][0];
		}
	}
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			e[i][j][0]=aux[i][j];
		}
	}
}
void dfsE(int i,int j,int p){
	if(i>6||j>6||i<0||j<0||memo[i][j]||e[i][j][0]=='.')return;
	memo[i][j]=true;
	h*=P;
	h+=p;
	h%=MOD;
	h2*=P;
	h2+=p;
	for(int it=0;it<4;it++){
		dfsE(i+dx[it],j+dy[it],it+1);
	}
}
void dfs(int i,int j,char k,int p){
	if(i>=n||j>=c||i<0||j<0||memo[i][j]||m[i][j]!=k)return;
	memo[i][j]=true;
	h*=P;
	h+=p;
	h%=MOD;
	h2*=P;
	h2+=p;
	for(int it=0;it<4;it++){
		dfs(i+dx[it],j+dy[it],k,it+1);
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>c;
		for(int i=0;i<n;i++){
			for(int j=0;j<c;j++){
				cin>>m[i][j];
			}
		}
		for(int it=0;it<4;it++){
			memset(memo,0,sizeof(memo));
			h=h2=1;
			for(int i=0;i<7;i++){
				for(int j=0;j<7;j++){
					if(!memo[i][j]&&a[i][j][0]!='.')dfsA(i,j,0);
				}
				sols[make_pair(h,h2)]=1;
			}
			rotaA();
		}
		for(int it=0;it<4;it++){
			memset(memo,0,sizeof(memo));
			h=h2=1;
			for(int i=0;i<7;i++){
				for(int j=0;j<7;j++){
					if(!memo[i][j]&&b[i][j][0]!='.')dfsB(i,j,0);
				}
				sols[make_pair(h,h2)]=2;
			}
			rotaB();
		}
		for(int it=0;it<4;it++){
			memset(memo,0,sizeof(memo));
			h=h2=1;
			for(int i=0;i<7;i++){
				for(int j=0;j<7;j++){
					if(!memo[i][j]&&ca[i][j][0]!='.')dfsC(i,j,0);
				}
				sols[make_pair(h,h2)]=3;
			}
			rotaC();
		}
		for(int it=0;it<4;it++){
			memset(memo,0,sizeof(memo));
			h=h2=1;
			for(int i=0;i<7;i++){
				for(int j=0;j<7;j++){
					if(!memo[i][j]&&d[i][j][0]!='.')dfsD(i,j,0);
				}
				sols[make_pair(h,h2)]=4;
			}
			rotaD();
		}
		for(int it=0;it<4;it++){
			memset(memo,0,sizeof(memo));
			h=h2=1;
			for(int i=0;i<7;i++){
				for(int j=0;j<7;j++){
					if(!memo[i][j]&&e[i][j][0]!='.')dfsE(i,j,0);
				}
				sols[make_pair(h,h2)]=5;
			}
			rotaE();
		}
		memset(memo,0,sizeof(memo));
		for(int i=0;i<n;i++){
			for(int j=0;j<c;j++){
				if(!memo[i][j]&&m[i][j]!='.'){
					h=h2=1;
					dfs(i,j,m[i][j],0);
					res[sols[make_pair(h,h2)]]++;
				}
			}
		}
		for(int i=1;i<=5;i++)cout << res[i]<<"\n";
	}
