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
			idx++;
			while(memo[idx])idx=(idx+1)%n;
			v[i]%=((n-i)+1);
			for(int j=1;j<=v[i];){
				if(!memo[idx])j++;
				if(j<=v[i])idx=(idx+1)%n;
			}
			idx%=n;
			while(memo[idx])idx=(idx+1)%n;
			cout << idx+1<<" ";
			memo[idx]=true;
			idx++;
			while(memo[idx])idx=(idx+1)%n;
		}
		cout << "\n";
	}
