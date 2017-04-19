#include <bits/stdc++.h>
using namespace std;
#define MAX 102
#define ll long long
int n;
ll v[MAX];
ll DP[MAX];
ll li,lf;
ll in,fin,mid;
bool solve(ll x){
	for(int i=1;i<=n;i++){
		if(DP[i-1]<v[i]){
			DP[i]=max(DP[i-1]+1,v[i]-x);
		}
		else {
			if(DP[i-1]>=v[i]+x)return false;
			DP[i]=DP[i-1]+1;
		}
	}
	return true;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i];
		}
		fin=(1<<30);
		while(in<=fin){
			mid=(in+fin)/2;
			if(solve(mid)){
				lf=mid;
				fin=mid-1;
			}
			else {
				li=mid;
				in=mid+1;
			}
		}
		if(solve(lf))cout<<lf<<"\n";
		else cout << li<<"\n"; 
	}
