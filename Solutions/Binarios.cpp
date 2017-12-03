#include <bits/stdc++.h>
using namespace std;
int res,s;
string v;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>v;
		for(int i=0;i<v.size();i++){
			if(v[i]=='1'){
				if(!(i&1))s++;
				else s+=2;
			}
			s%=3;
		}
		for(int i=v.size()-1;i>=0;i--){
			if(!s)res++;
			if(v[i]=='1'){
				if(!(i&1))s--;
				else s-=2;
			}
			s+=3;
			s%=3;
		}
		cout << res<<"\n";
	}
