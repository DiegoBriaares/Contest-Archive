#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
int v[MAX];
bool isprime(int n){
	int i,j;
	if(n==1)return false;
	i=sqrt(n);
	while(i>1){
		if(n%i==0)return false;
		i--;
	}
	return true;
}
void criba(){
	for(int i=2;i<=MAX;i++){
		if(v[i]==1)for(int j=i;j<=MAX;j+=i){
			v[j]=i;
		}
	}
}
bool test(int n){
	int i=n,j=0;
	while(i>1){
		j++;
		i/=v[i];
	}
	if(isprime(j))return true;
	else return false;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		for(int i=0;i<=MAX;i++)v[i]=1;
		criba();
		int a,b,r=0;
		cin>>a>>b;
		while(a<=b){
			if(test(a)&&a!=1)r++;
			a++;
		}
		cout << r <<"\n";
	}
