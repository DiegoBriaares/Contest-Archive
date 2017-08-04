#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
#define ll long long
ll r;
ll n,a,b;
pair<ll,ll> v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>a>>b;
		for(int i=0;i<n;i++){
			cin>>v[i].first>>v[i].second;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j)continue;
				ll area=(v[i].first*v[i].second)+(v[j].first*v[j].second);
				ll x,y,x_1,y_1,x_0,y_0;
				if(a-v[i].first>=0&&b-v[i].second>=0){
					x=a,y=b,x_1=v[i].first,y_1=v[i].second;
					x_0=(x-x_1),y_0=y_1;
					if(v[j].first<=x_0&&v[j].second<=y_0||v[j].first<=y_0&&v[j].second<=x_0)r=max(r,area);
					x_0=x,y_0=(y-y_1);
					if(v[j].first<=x_0&&v[j].second<=y_0||v[j].first<=y_0&&v[j].second<=x_0)r=max(r,area);
				}
				else if(b-v[i].first>=0&&a-v[i].second>=0){
					x=b,y=a,x_1=v[i].first,y_1=v[i].second;
					x_0=(x-x_1),y_0=y_1;
					if(v[j].first<=x_0&&v[j].second<=y_0||v[j].first<=y_0&&v[j].second<=x_0)r=max(r,area);
					x_0=x,y_0=(y-y_1);
					if(v[j].first<=x_0&&v[j].second<=y_0||v[j].first<=y_0&&v[j].second<=x_0)r=max(r,area);
				}
			}
		}
		cout << r<<"\n";
	}
