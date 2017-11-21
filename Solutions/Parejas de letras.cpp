#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
long long n,r=0,h[28];
char v[MAX],uso;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>uso;
			for(int j=uso+1;j<='z';j++){
				r+=h[j];
			}
			h[uso]++;
		}
		cout <<r<<"\n";
	}
