#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
#define INF 99999999999999999
ll res;
ll n,k;
string v;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>v;
		n=v.size();
		for(int i=n-1;i>=0;i--){
			if(v[i]!='('){
				int p=0,c=0;
				p=1;
				for(int j=i-1;j>=0;j--){
					if(v[j]=='?'){
						c++;
					}
					else if(v[j]==')'){
						p++;
					}
					else {
						p--;
					}
					if(p<0)break;
					if(p==0&&c%2==0)res++;
					else {
						if(p-c==0)res++;
					}
				}
			}
		}
		cout << res+1<<"\n";
	}
