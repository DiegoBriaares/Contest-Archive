#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
ll n,k;
string v;
int l,d,u,r;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		cin>>v;
		for(int i=0;i<n;i++){
			if(v[i]=='L')l++;
			if(v[i]=='D')d++;
			if(v[i]=='U')u++;
			if(v[i]=='R')r++;
		}
		
		n-=(max(l,r)-min(l,r));
		n-=(max(u,d)-min(u,d));
		cout << n<<"\n";
	}
