#include <bits/stdc++.h>
using namespace std;
#define MAX 310002
#define ll long long
#define INF 99999999999999999
ll v[MAX];
ll n,k,sum;
priority_queue<ll>cola;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i];
			cola.push(-v[i]);
		}
		if(n%2==0)cola.push(0);
		while(cola.size()>1){
			ll a=cola.top();
			cola.pop();
			ll b=cola.top();
			cola.pop();
			ll c=cola.top();
			cola.pop();
			sum=(-a)+(-b)+(-c);
			k+=sum;
			cola.push(-sum);
		}
		cout << k<<"\n";
	}
