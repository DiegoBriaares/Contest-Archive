#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
ll n;
string v;
bool solve(int k){
	for(int c=0;c<26;c++){
		bool ok=false;
		int s=0;
		for(int i=0;i<k;i++){
			if(v[i]-'a'==c)s++;
		}
		if(s==0)continue;
		for(int i=k;i<n;i++){
			if(v[i]-'a'==c)s++;
			if(v[i-k]-'a'==c)s--;
			if(s<=0){
				ok=true;
				break;
			}
		}
		if(!ok){
			return true;
		}
	}
	return false;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>v;
		n=v.size();
		int in=0,fin=n,la=0;
		while(in<=fin){
			int mid=(in+fin)/2;
			if(solve(mid)){
				fin=mid-1;
				la=mid;
			}
			else in=mid+1;
		}
		cout << la<<"\n";
	}
