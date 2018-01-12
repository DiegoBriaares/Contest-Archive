#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
ll n,k;
ll v[MAX];
bool memo[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		for(int i=1;i<=k;i++){
			cin>>v[i];
		}
		int idx=0;
		for(int i=1;i<=k;i++){
			v[i]%=((n-i)+1);
			int aux=idx;
			while(v[i]){
				aux=(aux+1)%n;
				if(!memo[aux])v[i]--;
			}
			cout << aux+1<<" ";
			memo[aux]=true;
			idx=(aux+1)%n;
			while(memo[idx])idx=(idx+1)%n;
		}
		cout << "\n";
	}
