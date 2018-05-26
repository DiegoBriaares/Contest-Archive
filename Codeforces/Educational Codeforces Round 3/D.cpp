#include <bits/stdc++.h>
using namespace std;
#define MAX 3100002
#define ll long long
ll n,m,k,s;
ll a[MAX],b[MAX];
vector<pair<ll,ll> >ame,ing;
vector<pair<ll,ll> >resp,aux;
bool solve(ll x){
	ll barD,barL,dD,dL;
	barD=barL=-1;
	for(int i=0;i<x;i++){
		if(barD==-1||a[i]<barD){
			barD=a[i];
			dD=i+1;
		}
		if(barL==-1||b[i]<barL){
			barL=b[i];
			dL=i+1;
		}
	}
	aux.clear();
	ll dol,lib,t;
	dol=lib=0,t=s;
	for(int i=0;i<k;i++){
	//	if(x==3)cout << "ENTRE: "<<dol<<" "<<lib<<" "<<barD<< " "<<barL<<"\n";
		if(dol<ame.size()&&lib<ing.size()&&barD*ame[dol].first<barL*ing[lib].first){
			t-=(barD*ame[dol].first);
			aux.push_back(make_pair(ame[dol].second,dD));
			dol++;
		}
		else if(dol<ame.size()&&lib<ing.size()&&barD*ame[dol].first>=barL*ing[lib].first){
			t-=(barL*ing[lib].first);
			aux.push_back(make_pair(ing[lib].second,dL));
			lib++;
		}
		else if(dol<ame.size()){
			t-=(barD*ame[dol].first);
			aux.push_back(make_pair(ame[dol].second,dD));
			dol++;
		}
		else if(lib<ing.size()){
			t-=(barL*ing[lib].first);
			aux.push_back(make_pair(ing[lib].second,dL));
			lib++;
		}
		else return false;
		if(t<0)return false;
	}
	resp=aux;
	return true;
}
int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	for(int i=0;i<m;i++){
		ll t,x;
		cin>>t>>x;
		if(t==1)ame.push_back(make_pair(x,i+1));
		else ing.push_back(make_pair(x,i+1));
	}
	sort(ame.begin(),ame.end());
	sort(ing.begin(),ing.end());
	ll in=1,fin=n,la=-1;
	while(in<=fin){
		ll mid=(in+fin)/2LL;
		if(solve(mid)){
			la=mid;
			fin=mid-1;
		}
		else in=mid+1;
	}
	cout << la<<"\n";
	sort(resp.begin(),resp.end());
	if(la!=-1){
		for(int i=0;i<resp.size();i++){
			cout << resp[i].first<<" "<<resp[i].second<<"\n";
		}
	}
}
