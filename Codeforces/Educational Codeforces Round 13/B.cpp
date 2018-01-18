#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
ll n,n2,res;
int leap(int k){
	if(k%400==0)return 1;
	if(k%4==0&&k%100!=0)return 1;
	return 0;
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		ll l=leap(n);
		n++;
		ll day=1+leap(n);
		while(1){
			if(day%7==0&&leap(n)==l)break;
			n++;
			day+=1+leap(n);
		}
		cout << n<<"\n";
	}
