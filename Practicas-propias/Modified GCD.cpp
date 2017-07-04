#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 10000003
ll a,b;
ll l,r;
bool eratos[MAX];
vector<ll>divi;
map<ll,bool>memo;
vector<pair<ll,int> >fact;
void criba(){
	for(int i=2;i<MAX;){
		if(!eratos[i]){
			for(int j=i+i;j<MAX;j+=i)
				eratos[i]=true;
		}
		if(i==2)i++;
		else i+=2;
	}
}
vector<ll>v;
void get_primes(){
	for(int i=2;i<MAX;i++){
		if(eratos[i])v.push_back(i);
	}
}
bool is_prime(ll x){
	ll y=sqrt(x);
	while(y>1){
		if(x%y==0)return false;
		y--;
	}
	return true;
}
vector<int> desc(ll x){
	ll k=0;
	vector<int>res;
	while(k<v.size()&&v[k]<=x){
		if(x%v[k]==0){
			while(x%v[k]==0)x/=v[k],res.push_back(v[k]);
		}
		k++;
		if(k>=v.size())res.push_back(x);
	}
	return res;
}
void dfs(int i,ll num){
	if(i==fact.size()){
		if(!memo[num]){
			memo[num]=true;
			divi.push_back(num);	
		}
		return;
	}
	ll p=1;
	for(int j=0;j<=fact[i].second;j++){
		dfs(i+1,num*p);
		p*=fact[i].first;
	}
}
	int main (){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		criba();
		get_primes();
		cin>>a>>b;
		vector<int>p1,p2;
		if(!is_prime(a))p1=desc(a);
		else p1.push_back(a);
		if(!is_prime(b))p2=desc(b);
		else p2.push_back(b);
		if(p1.size()>p2.size())swap(p1,p2);
		for(int i=0,j=0;i<p1.size()&&j<p2.size();){
			int exp=0;
			int p=p1[i];
			while(i<p1.size()&&j<p2.size()&&p1[i]==p2[j]&&p1[i]==p){
				i++;
				j++;
				exp++;
			}
			if(exp)fact.push_back(make_pair(p,exp));
			while(i<p1.size()&&j<p2.size()&&p1[i]!=p2[j]){
				if(p1[i]<p2[j])i++;
				else j++;
			}
		}
		dfs(0,1);
		sort(divi.begin(),divi.end());
		int q;
		cin>>q;
		while(q--){
			cin>>l>>r;
			int idx=upper_bound(divi.begin(),divi.end(),r)-divi.begin();
			while(idx>=divi.size())idx--;
			if(idx<0){
				cout <<"-1\n";
				continue;
			}
			if(divi[idx]>r||divi[idx]<l){
				if(idx){
					idx--;
				}
			}
			if(divi[idx]>r||divi[idx]<l)cout <<"-1\n";
			else cout << divi[idx]<<"\n";
		}
	}
