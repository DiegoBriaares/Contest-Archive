#include <bits/stdc++.h>
using namespace std;
#define MAX 10002
int n;
int may;
bool day[MAX];
bool night[MAX];
pair<int,pair<int,int> > v[MAX];
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i].first>>v[i].second.first>>v[i].second.second;
			may=max(may,v[i].first);
		}
		int t=0;
		while(t<=1825*may){
			bool ok=false;
			for(int i=0;i<n;i++){
				int hour=(t%v[i].first);
				if(v[i].second.first<v[i].second.second){
					if(v[i].second.first<hour&&hour<v[i].second.second){
						ok=true;
						break;
					}
				}
				else {
					if(v[i].second.first<hour||hour<v[i].second.second){
						ok=true;
						break;
					}
				}
			}
			if(!ok){
				cout << t<<"\n";
				return 0;
			}
			t++;
		}
		cout << "impossible\n";
	}

