#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
int n;
string a,b,c;
map<char,char>memo;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>a>>b>>c;
		for(int i=0;i<a.size();i++){
			memo[a[i]]=b[i];
		}
		for(int i=0;i<c.size();i++){
			if(c[i]>='0'&&c[i]<='9'){
				cout << c[i];
			}
			else if(c[i]>='A'&&c[i]<='Z'){
				c[i]+=('a'-'A');
				char x=memo[c[i]]-('a'-'A');
				cout << x;
			}
			else cout << memo[c[i]];
		}
	}
