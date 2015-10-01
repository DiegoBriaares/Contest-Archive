#include <bits/stdc++.h>
using namespace std;
	int main (){
		int n,i,j,k,ts=0,fs=0;
		string v;
		cin>>n;
		cin>>v;
		cin>>k;
		for(i=0;i<v.size();i++){
			if(v[i]=='T')ts++;
			if(v[i]=='F')fs++;
		}
		if(k==ts){
		cout << v.size();
		return 0;
		}
		else if(k<ts){
			//Aquí dentro todo lo del recorrido :P	
		}
		k-=ts;
		if(k%2!=0){
			cout <<ts+fs-1;
		}
		else cout <<v.size();
	}
