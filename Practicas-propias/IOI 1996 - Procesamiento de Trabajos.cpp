#include <bits/stdc++.h>
using namespace std;
#define MAX 1000002
int n;
int a,b,r;
int v[MAX];
int v2[MAX];
int arr[MAX];
priority_queue<pair<int,int> >A,B;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		cin>>a;
		for(int i=0;i<a;i++){
			cin>>v[i];
			A.push(make_pair(-v[i],i));
		}
		cin>>b;
		for(int i=0;i<b;i++){
			cin>>v2[i];
			B.push(make_pair(-v2[i],i));
		}
		for(int i=0;i<n;i++){
			pair<int,int> aux=A.top();
			A.pop();
			arr[i]=(-aux.first);
			A.push(make_pair(-((-aux.first)+v[aux.second]),aux.second));
		}
		reverse(arr,arr+n);
		for(int i=0;i<n;i++){
			pair<int,int> aux=B.top();
			B.pop();
			r=max(r,-aux.first+arr[i]);
			//cout << "AUX: "<<arr[i]<<" "<<-aux.first<<"\n";
			B.push(make_pair((-((-aux.first)+v2[aux.second])),aux.second));
		}
		cout << arr[0]<<"\n"<<r<<"\n";
	}
