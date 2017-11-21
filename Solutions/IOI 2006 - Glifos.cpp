#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
#define ll long long
int r;
int n,m;
string a,b;
int h[MAX];
int v[MAX];
	int main (){
		ios_base::sync_with_stdio();
		cin.tie(0);
		cin>>n>>m;
		cin>>a>>b;
		for(int i=0;i<n;i++){
			h[a[i]]++;
		}
		int us=0,k=0;
		for(int i=0;i<m;i++){
			us++;
			v[b[i]]++;
			while(v[b[i]]>h[b[i]]){
				us--;
				v[b[k]]--;
				k++;
			}
			if(us==n)r++;
		}
		cout << r<<"\n";
	}
