#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
int k;
int r,c;
string v;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>v>>k;
		reverse(v.begin(),v.end());
		for(int i=0;i<v.size();i++){
			if(v[i]>'0'){
				r++;
			}
			else c++;
			if(c==k)break;
		}
		if(c<k)cout << v.size()-1<<"\n";
		else cout << r<<"\n";
	}
