#include <bits/stdc++.h>
using namespace std;
int a,b;
vector<int>v;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>a>>b;
		int s=0;
		for(int i=b;i>=1;i--){
			if(s+(i& -i)<=a){
				s+=(i & -i);
				v.push_back(i);
			}
			if(s>=a)break;
		}
		if(s!=a)cout <<-1;
		else {
			cout<<v.size()<<"\n";
			for(int i=0;i<v.size();i++)cout << v[i]<<" ";
		}
	}
