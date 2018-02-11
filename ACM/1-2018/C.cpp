#include <bits/stdc++.h>
using namespace std;
#define MAX 32
int n;
int may,red,sum;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			string v;
			cin>>v;
			int val;
			if(v=="black")val=7;
			if(v=="pink")val=6;
			if(v=="blue")val=5;
			if(v=="brown")val=4;
			if(v=="green")val=3;
			if(v=="yellow")val=2;
			if(v=="red")val=1,red++;
			sum+=val;
			may=max(may,val);
		}
		if(may==1){
			cout << "1\n";
			return 0;
		}
		cout << (may*red)+sum<<"\n";
	}
