#include <bits/stdc++.h>
using namespace std;
#define MAX 300002
int n,r;
string aux;
string a,b;
int v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>a>>b;
		n=a.size();
		int idx=0;
		for(int i=0;i<n;i++){
			cin>>v[i];
			v[i]--;
		}
		int in=0,fin=n;
		while(in<fin){
			int mid=in+(fin-in+1)/2;
			aux=a;
			for(int i=0;i<mid;i++){
				aux[v[i]]='.';
			}
			idx=0;
			for(int i=0;idx<b.size()&&i<n;i++){
				if(aux[i]==b[idx])idx++;
			}
			if(idx==b.size()){
				r=max(r,mid);
				in=mid;
			}
			else fin=mid-1;
		}
		cout << r<<"\n";
	}
