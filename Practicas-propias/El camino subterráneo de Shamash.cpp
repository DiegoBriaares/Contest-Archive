#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
queue<string>year;
void add(int x){
	string v="";
	int uso=(x%10);
	x/=10;
	while(uso>0){
		v+="I";
		uso--;
	}
	uso=(x%10);
	while(uso>0){
		v+="L";
		uso--;
	}
	reverse(v.begin(),v.end());
	year.push(v);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		add(n%60);
		n/=60;
		while(n>0){
			year.push(".");
			add(n%60);
			n/=60;
		}
		while(!year.empty()){
			cout <<year.front();
			year.pop();
		}
	}
