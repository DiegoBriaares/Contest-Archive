#include <bits/stdc++.h>
using namespace std;
#define MAX 1000102
#define ll long long
#define MOD 1000000007
ll a,b,c;
int v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>a>>b>>c;
		v[a]++;
		v[b]++;
		v[c]++;
		if(v[1]){
			cout <<"YES\n";
			return 0;
		}
		
		if(v[2]>=2){
			cout <<"YES\n";
			return 0;
		}
		if(v[3]==3){
			cout <<"YES\n";
			return 0;
		}
		if(v[2]&&v[4]==2){
			cout <<"YES\n";
			return 0;
		}
		cout << "NO\n";
	}
