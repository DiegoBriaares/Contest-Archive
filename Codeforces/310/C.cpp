#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
ll n,k;
int res;
vector<vector<int> >arr;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>k;
		for(int i=0;i<k;i++){
			int x;
			vector<int>vec;
			cin>>x;
			for(int j=0;j<x;j++){
				int y;
				cin>>y;
				vec.push_back(y);
			}
			arr.push_back(vec);
		}
		sort(arr.begin(),arr.end());
		int sum=0;
		vector<int>v=arr[0];
		for(int j=1;j<v.size();j++){
			if(v[j]!=j+1){
				sum+=((int)v.size()-(j));
				sum+=((int)v.size())-(j);
				break;
			}
		}
		for(int i=1;i<arr.size();i++){
			sum+=(arr[i].size())-1;
			sum+=(arr[i].size());
		}
		
		cout << sum<<"\n";
	}
