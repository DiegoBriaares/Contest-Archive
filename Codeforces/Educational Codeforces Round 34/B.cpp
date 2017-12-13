#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define MOD 1000000007
#define ll long long
ll h2,a2;
ll v[MAX];
ll h,a,c,r;
vector<string>res;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>h>>a>>c;
		cin>>h2>>a2;
		while(h2>0){
			if(h-a2<=0&&h2-a<=0){
				res.push_back("STRIKE");
				break;
			}
			if(h-a2<=0){
				h+=c;
				h-=a2;
				res.push_back("HEAL");
			}
			else {
				h2-=a;
				h-=a2;
				res.push_back("STRIKE");
			}
		}
		cout << res.size()<< "\n";
		for(int i=0;i<res.size();i++)cout << res[i]<<"\n";
	}
