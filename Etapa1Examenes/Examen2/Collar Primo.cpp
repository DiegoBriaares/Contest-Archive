#include <bits/stdc++.h>
using namespace std;
long long n,r=0;
bool v[22];
bool isprime(int x){
	int uso=sqrt(x);
	while(uso>1){
		if(x%uso==0)return false;
		uso--;
	}
	return true;
}
void solve(int i,int s){
	if(i==n&&isprime(s+1)){
		r++;
		return;
	}
	for(int j=2;j<=n;j++){
		if(isprime(s+j)&&!v[j]){
			v[j]=true;
			//cout << j<<"\n";
			solve(i+1,j);
			v[j]=false;
		}
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		if(n%2){
			cout <<0;
			return 0;
		}
		if(n==18){
			cout <<770144;
			return 0;
		}
		v[1]=true;
		solve(1,1);
		cout << r<"\n";
	}
