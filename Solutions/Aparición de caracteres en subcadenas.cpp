#include <bits/stdc++.h>
using namespace std;
char x;
string s;
map<char,bool>h;
int q,a,b,n;
vector<int>v;
map<char,vector<int> >memo;
int bs(int in,int fin){
	int mid=(in+fin)/2;
	if(v[mid]>=a&&v[mid]<=b)return true;
	if(in>=fin)return false;
	if(v[mid]<=a)return bs(mid+1,fin);
	else if(v[mid]>=b)return bs(in,mid);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>s;
		for(int i=0;i<s.size();i++){
			memo[s[i]].push_back(i);
			h[s[i]]=true;
		}
		cin>>q;
		while(q--){
			cin>>x>>a>>b;
			b=(a+b)-1;
			if(!h[x]){
				cout << "0\n";
				continue;
			}
			v=memo[x];
			n=v.size();
			cout << bs(0,n-1)<<"\n";
		}
	}
