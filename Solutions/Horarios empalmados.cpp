#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define in second
#define fin first
int n;
int r,t;
pair<int,int>v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i].in>>v[i].fin;
		}
		r=1;
		sort(v,v+n);
		t=v[0].fin;
		for(int i=1;i<n;i++){
			while(i<n&&v[i].in<t)i++;
			if(i<n){
				t=v[i].fin;
				r++;
			}
		}
		cout << r<<"\n";
	}
