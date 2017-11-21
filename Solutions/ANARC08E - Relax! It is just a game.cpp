#include <bits/stdc++.h>
using namespace std;
#define MAX 12 
int memo[MAX][MAX];
int dp(int x,int y){
	if(x==0&&y==0)return 1;
	if(x<0||y<0)return 0;
	if(memo[x][y])return memo[x][y];
	return memo[x][y]=dp(x-1,y)+dp(x,y-1);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int x,y;
		while(1){
			memset(memo,0,sizeof(memo));
			cin>>x>>y;
			if(x==-1&&y==-1)return 0;
			if(dp(x,y)!=(x+y))cout << x<<"+"<<y<<"!="<<(x+y)<<"\n";
			else cout << x<<"+"<<y<<"="<<(x+y)<<"\n";
		}
	}
