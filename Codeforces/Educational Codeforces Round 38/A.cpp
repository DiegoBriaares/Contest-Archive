#include <bits/stdc++.h>
using namespace std;
#define MAX 301002
#define ll long long
#define MOD 1000000007
ll n,k;
string v;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		cin>>v;
		cout << v[0];
		for(int i=1;i<v.size();i++){
			if(v[i-1]=='a'||v[i-1]=='e'||v[i-1]=='i'||v[i-1]=='o'||v[i-1]=='u'||v[i-1]=='y'){
				if(v[i]=='a'||v[i]=='e'||v[i]=='i'||v[i]=='o'||v[i]=='u'||v[i]=='y')continue;
				cout << v[i];
			}
			else cout << v[i];
		}
		cout << "\n";
	}
