#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1000002
ll n,k;
bool ondulado(ll x){
	char v[MAX];
	int i,j,n;
	for(i=0;x>0;i++,x/=10){
		v[i]=(x%10)+48;
	}
	reverse(v,v+i);
	n=i;
	i=0,j=n-1;
	if(i+1==j&&v[i]!=v[j])return true;
	if(v[i]>v[i+1]&&v[j]>v[j-1]||v[i]<v[i+1]&&v[j]<v[j-1]){
		i++;
		j--;
		while(i<j){
			if(v[i]>v[i-1]&&v[j]>v[j+1]&&(i+1==j?1:v[i]>v[i+1]&&v[j]>v[j-1])||v[i]<v[i-1]&&v[j]<v[j+1]&&(i+1==j?1:v[i]<v[i+1]&&v[j]<v[j-1])){
				i++;
				j--;
			}
			else return false;
		}
		return true;
	}
	else return false;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		ll uso=1,r=0;
		for(int i=n;1;i+=n){
			if(i%n==0&&ondulado(i)){
				uso++;
				r+=i;
				cout <<"R: "<< i<<"\n";
			}
			if(uso>=k){
				cout << r<<"\n";
				return 0;
			}
			if(i>=10000000000){
				cout <<-1<<"\n";
				return 0;
			}
		}
	}
