#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define MAX_LOG 18
#define ll long long
#define MOD 1000000007
ll n;
ll res;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				ll s=(j^i);
				if(s>=j&&s<=n&&(i+j>s&&i+s>j&&j+s>i))res++;
			}
		}
		cout << res<<"\n";
	}
