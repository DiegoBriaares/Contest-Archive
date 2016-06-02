#include <bits/stdc++.h>
using namespace std;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		string v;
		int i=0;
		getline(cin,v);
		cout <<"if(";
		while(1){
			if(v[i]=='?'){
				i++;
				 break;
			}
			cout <<v[i++];
		}
		cout <<")\n";
		cout << "	";
		while(1){
			if(v[i]==':'){
				i++;
				 break;
			}
			cout <<v[i++];
		}
		cout <<";\nelse\n";
		cout << "	";
		while(i<v.size()){
			cout <<v[i++];
		}
		cout <<";";
	}
