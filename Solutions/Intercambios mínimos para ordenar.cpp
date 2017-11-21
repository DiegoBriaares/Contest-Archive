#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
#define ll long long
int n,r;
bool memo[MAX];
ll h[MAX];
pair<ll,ll> arr[MAX];
void dfs(ll nodo){
	if(memo[nodo]||memo[h[nodo]]||nodo==h[nodo])return;
	r++;
	memo[nodo]=true;
	int aux=h[nodo];
	h[nodo]=nodo;
	dfs(aux);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>arr[i].first;
			arr[i].second=i;
		}
		sort(arr,arr+n);
		for(int i=0;i<n;i++){
			h[arr[i].second]=i;
		}
		for(ll i=0;i<n;i++){
			if(!memo[i]){
				dfs(i);
			}
		}
		cout << r<<"\n";
	}
