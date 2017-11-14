#include <bits/stdc++.h>
using namespace std;
#define MAX 5002
#define ll long long
ll n,k;
vector<int>v;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		for(int i=0;i<6;i++){
			int x;
			cin>>x;
			v.push_back(x);
		}
		sort(v.begin(),v.end());
		do {
			int s=0,s2=0;
			for(int i=0;i<3;i++){
				s+=v[i];
			}
			for(int i=3;i<6;i++){
				s2+=v[i];
			}
			if(s==s2){
				cout << "YES\n";
				return 0;
			}
		}while(next_permutation(v.begin(),v.end()));
		cout << "NO\n";
	}
