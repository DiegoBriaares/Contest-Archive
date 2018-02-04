#include <bits/stdc++.h>
using namespace std;
#define MAX 2102
#define ll long long
#define INF 9999999999999
ll res;
ll n,k,c;
char m[MAX][MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>c>>k;
		for(int i=0;i<n;i++){
			for(int j=0;j<c;j++){
				cin>>m[i][j];
			}
		}
		for(int i=0;i<n;i++){
			int dots=0;
			for(int j=0;j<c;j++){
				if(m[i][j]=='.')dots++;
				else {
					if(dots>=k)res+=(dots-k)+1;
					dots=0;
				}
			}
			if(dots>=k)res+=(dots-k)+1;
		}
		for(int j=0;j<c;j++){
			int dots=0;
			for(int i=0;i<n;i++){
				if(m[i][j]=='.')dots++;
				else {
					if(dots>=k)res+=(dots-k)+1;
					dots=0;
				}
			}
			if(dots>=k)res+=(dots-k)+1;
		}
		if(n==1&&res%2==0||k==1&&res%2==0)res/=2;
		cout << res<<"\n";
	}
