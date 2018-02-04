#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
#define INF 99999999999999999
ll res;
ll n,k;
ll fib[MAX];
map<ll,bool>h;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		fib[0]=fib[1]=1;
		h[1]=true;
		for(int i=2;i<50;i++){
			fib[i]=fib[i-1]+fib[i-2];
			h[fib[i]]=true;
			if(fib[i]>n)break;
		}
		for(int i=1;i<=n;i++){
			if(h[i])cout << "O";
			else cout <<"o";
		}
		cout << "\n";
	}
