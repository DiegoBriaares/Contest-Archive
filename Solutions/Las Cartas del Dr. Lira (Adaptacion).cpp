#include <bits/stdc++.h>
using namespace std;
#define MAX 52
bool v[MAX];
int n;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		int a=0,b=0;
		if(!v[0]){
			for(int i=0;i<n;i++){
				if(!(i&1)&&v[i]||(i&1)&&!v[i])a++;
				if(!(i&1)&&!v[i]||(i&1)&&v[i])b++;
			}
			cout << min(a,b)<<"\n";
		}
		else {
			for(int i=0;i<n;i++){
				if(!(i&1)&&v[i]||(i&1)&&!v[i])b++;
				if(!(i&1)&&!v[i]||(i&1)&&v[i])a++;
			}
			cout << min(a,b)<<"\n";
		}
	}
