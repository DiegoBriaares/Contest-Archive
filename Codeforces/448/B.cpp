#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
long long n,r,s;
string a,b;
long long dp[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>a;
		cin>>b;
		n=b.size();
		for(int i=1;i<=b.size();i++){
			dp[i]=dp[i-1];
			dp[i]+=b[i-1]-'0';
		}
		for(int i=1;i<=a.size();i++){
			if(a[i-1]=='0')s+=(dp[n-(a.size()-i)]-dp[i-1]);
			else {
				s+=((n-(a.size()-i)-i)+1)-(dp[n-(a.size()-i)]-dp[i-1]);
			}
		}
		
		cout << s<<"\n";
	}
