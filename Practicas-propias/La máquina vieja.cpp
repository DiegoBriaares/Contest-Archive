#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
#define fin second.first
#define im second.second
#define in first
int n,r;
int memo[MAX][MAX];
pair<int,pair<int,int> >v[MAX];
int dp(int i,int j){
	if(i==n)return 0;
	int ans=dp(i+1,j);
	int b=v[j].fin;
	if(v[i].in<b)return ans;
	if(memo[i][j])return memo[i][j];
	return memo[i][j]=max(ans,dp(i+1,i)+v[i].im);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i].in>>v[i].fin>>v[i].im;
		}
		sort(v,v+n);
		for(int i=0;i<n;i++){
			r=max(r,dp(i+1,i)+v[i].im);
		}
		cout << r<<"\n";
	}
