#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
pair<pair<int,string>,int>v[MAX];
int bs(int in,int fin,int x){
	if(in==fin)return in;
	int mid=(in+fin)/2;
	if(v[mid].first.first>x)return bs(in,mid,x);
	else return bs(mid+1,fin,x);
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int n,k,x;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i].first.second>>v[i].second>>v[i].first.first;
		}
		sort(v,v+n);
		cin>>k;
		for(int i=0;i<k;i++){
			cin>>x;
			int pos=bs(0,n-1,x),r=0;
		//	cout <<"R: "<<pos<<"\n";
			string res;
			for(int j=pos;j<n&&x<=v[j].first.first;j++){
				if(x>=v[j].second&&x<=v[j].first.first){
					res=v[j].first.second;
					r++;
				}
				if(r>1)break;
			}
			if(r>1)cout << "MULTIPLE\n";
			if(r==1)cout << res<<"\n";
			if(r==0)cout << "NONE\n";
		}
	}
