#include <bits/stdc++.h>
using namespace std;
bool lucky(int n){
	while(n>0){
		if(n%10!=4&&n%10!=7){
			return false;
		}
		n/=10;
	}
	return true;
}
	int main (){
		int n,i,j,k,g,h;
		cin>>n;
		if(lucky(n)){
			cout <<"YES";
		}
		else {
			for(i=1;i<=n;i++){
				if(lucky(i)){
					if(n%i==0){
						cout <<"YES";
						return 0;
					}
				}
			}
			cout <<"NO";
		}
	}
