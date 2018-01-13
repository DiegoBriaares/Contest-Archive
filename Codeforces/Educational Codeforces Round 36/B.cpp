#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
#define INF 999999999999999999
ll res;
ll n,k,l,r,pos;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>pos>>l>>r;
		if(l==1&&r==n){
			cout << "0\n";
			return 0;
		}
		if(abs(l-pos)<abs(r-pos)){
			res+=abs(l-pos);
			if(l>1)res++;
			if(r<n){
				res+=abs(l-r);
				res++;
			}
			
		}
		else {
			res+=abs(r-pos);
			if(r<n)res++;
			if(l>1){
				res+=abs(l-r);
				res++;
			}
			
		}
		cout << res<<"\n";
	}
