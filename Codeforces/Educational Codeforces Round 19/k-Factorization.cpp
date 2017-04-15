#include <bits/stdc++.h>
using namespace std;
int p=2;
int n,k;
vector<int>prim;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		while(n>1){
			if(n%p==0){
				while(n%p==0){
					n/=p;
					prim.push_back(p);
				}
			}
			if(p==2)p++;
			else p+=2;
		}
		if(prim.size()<k){
			cout << "-1\n";
			return 0;
		}
		int s=prim.size()-1;
		while(s>=k&&s){
			prim[s-1]*=prim[s];
			s--;
		}
		for(int i=0;i<k;i++){
			cout << prim[i]<<" ";
		}
		cout << "\n";
	}
