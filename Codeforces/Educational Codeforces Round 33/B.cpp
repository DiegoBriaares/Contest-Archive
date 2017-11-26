#include <bits/stdc++.h>
using namespace std;
#define MAX 300002
#define ll long long
ll n,k;
ll v[MAX];
map<ll,bool>memo;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		for(int i=1;i<20;i++){
			cout << "AUX: "<<((1LL<<(i))-1)*((1LL<<(i-1)))<<"\n";
			memo[((1LL<<(i))-1)*((1LL<<(i-1)))]=true;
		}
		
		cin>>n;
		for(int i=n;i>=1;i--){
			if(n%i==0&&memo[i]){
				cout << i<<"\n";
				return 0;
			}
		}
		
	}
