#include <bits/stdc++.h>
using namespace std;
char m[4][4];
int memo[4][4];
string v;
int dp(int i,int j,int s){
	if(memo[i][j])return -(1<<20);
	if(i>=4||j>=4||i<0||j<0)return -(1<<20);
	if(m[i][j]!=v[s])return -(1<<20);
	if(s==v.size()-1)return 0;
	memo[i][j]=1;
	int a=max(max(1+dp(i+1,j,s+1),1+dp(i-1,j,s+1)),max(max(1+dp(i,j+1,s+1),1+dp(i,j-1,s+1)),max(max(1+dp(i+1,j+1,s+1),1+dp(i-1,j+1,s+1)),max(1+dp(i+1,j-1,s+1),1+dp(i-1,j-1,s+1)))));
	memo[i][j]=0;
	return a;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			cin>>m[i][j];
			int n;
			cin>>n;
			int g,h,j,i,r=0;
			for(int t=0;t<n;t++){
				cin>>v;
				g=1;
				for(int i=0;i<4;i++)
				for(int j=0;j<4;j++){
					if(m[i][j]==v[0])g=max(g,dp(i,j,0)+1);
				}
			if(g==3||g==4)r+=1;
			if(g==5)r+=2;
			if(g==6)r+=3;
			if(g==7)r+=5;
			if(g>=8)r+=11;
			}
			cout << r<<"\n";
	}
