#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
#define MOD 1000000007
ll a,b,res;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>a>>b;
		res=(b-1);
		if(b==1&&a>0||b==0)cout << "No\n";
		else if(res>a)cout << "No\n";
		else if((a-res)%2!=0)cout << "No\n";
		else cout << "Yes\n";
		
	}
