#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
int n;
ll v[MAX];
bool b;
bool d,s;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		if(n==1){
			cout << "YES\n";
			return 0;
		}
		for(int i=1;i<n;i++){
			if(d&&v[i]>v[i-1]||(d&&v[i]==v[i-1])||(s&&b&&v[i]>v[i-1])||(b&&v[i]>v[i-1])){
				cout << "NO\n";
				return 0;
			}
			if(v[i]>v[i-1])s=true;
			if(b&&v[i]<v[i-1])d=true;
			if(!b&&v[i]<v[i-1])b=true,d=true;
			if(v[i]==v[i-1])b=true;
		}
		cout << "YES\n";
	}
