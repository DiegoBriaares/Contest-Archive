#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
ll n,r;
ll v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		for(int i=0;i<n;i++){
			if(i>0&&i<n-1&&((v[i]<v[i-1]&&v[i]<v[i+1])||(v[i]>v[i-1]&&v[i]>v[i+1])))r++;
		}
		cout <<r<<"\n";
	}
