#include <bits/stdc++.h>
using namespace std;
#define MAX 100002
#define ll long long
ll s,k=(1<<30);
int idx;
bool ok;
int n;
ll v[MAX];
vector<pair<int,int> >impar;
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
			if(v[i]%2!=0){
				impar.push_back(make_pair(abs(v[i]),i));
			}
		}	
		sort(v,v+n);
		sort(impar.begin(),impar.end());
		for(int i=n-1;i>=0;i--){
			if(s+v[i]<s)break;
			idx=i;
			s+=v[i];
		}
		if(s%2==0){
			if(idx>impar[0].second){
				if(v[impar[0].second]<0)impar[0].first*=(-1);
				s+=impar[0].first;
			}
			else s-=abs(impar[0].first);
		}
		cout <<s<<"\n";
	}
